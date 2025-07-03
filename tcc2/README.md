# TCC 2

## SoftHSMv2

### Concepts

- Module: The PKCS#11 library itself (e.g., libsofthsm2.so). This is what pkcs11-tool needs to load to communicate with SoftHSM.
- Slot: A logical interface to a token. SoftHSM creates virtual slots.
- Token: A virtual cryptographic device residing in a slot. This is where your keys and certificates are stored. Each token has a label and can be initialized with a Security Officer (SO) PIN and a User PIN.
- PINs:
  - SO PIN: Used by the Security Officer to manage the token (e.g., initialize, reset user PIN).
  - User PIN: Used by regular applications to access the cryptographic objects (keys, certificates) on the token.
- Objects: The cryptographic items stored on a token, such as:
  - Public Keys: For verifying signatures, encrypting data.
  - Private Keys: For signing data, decrypting data.
  - Certificates: X.509 certificates.
  - Secret Keys: For symmetric encryption/decryption.

### Build & install

```bash
### Instalando pre requisitos
sudo apt install automake autoconf libtool pkg-config libssl-dev libsqlite3-dev libp11-kit-dev libcppunit-dev

### Preparação
sh autogen.sh

### Configuração de build
./configure --with-crypto-backend=openssl --with-objectstore-backend-db --disable-gost --enable-eddsa

### Compilando código fonte
make

### Testando
make check

### Instalando
sudo make install
```

### Conf file

You are not compelled to define it, the default conf file is in
/etc/softhsm2.conf

```bash
man softhsm2.conf
### Conf file
export SOFTHSM2_CONF=/home/user/my_softhsm2.conf
#### file
directories.tokendir = /var/lib/softhsm/tokens

### creating path token
sudo mkdir -p /var/lib/softhsm/tokens/ # Example path
sudo chown <your_user>:<your_group> /var/lib/softhsm/tokens/ # Adjust ownership if needed
```
### Init token

```bash
softhsm2-util --init-token --slot 0 --label "My SoftHSM Token" --so-pin 0000 --pin 0000
softhsm2-util --init-token --free  --label "My SoftHSM Token" --so-pin 0000 --pin 0000
softhsm2-util --delete-token --slot <slot> --serial <serial> --so-pin 0000
```

## pkcs11

```bash
sudo apt install opensc opensc-pkcs11


### Show available slots and token information
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so -L

### List objects
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --list-objects

#### List public objects withou login
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --list-objects --type pubkey

#### List available mechanisms
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so   --login --pin 0000   --sign   --id 02   --list-mechanism
```

### RSA 
```bash
### Gen RSA
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --keypairgen \
  --key-type rsa:2048 \ # ec:secp256r1
  --id 01 \ # Hexa value
  --label "My RSA Key" \
  --usage-sign --usage-decrypt # sign, decrypt, wrap, verify, encrypt, unwrap

### Sign
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --sign \
  --id 01 \
  --mechanism SHA256-RSA-PKCS \
  --input-file data.txt \
  --output-file data.sig

### Verify
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --verify \
  --id 01 \
  --mechanism SHA256-RSA-PKCS \
  --input-file data.txt \
  --signature-file data.sig

### Extract public key (DER format)
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --read-object --type pubkey --id 01 \
  --output-file my_rsa_key.pub.der

### Convert to PEM format (if needed for other tools like OpenSSL)
openssl rsa -inform DER -outform PEM -pubin -in my_rsa_key.pub.der -out my_rsa_key.pub.pem
```

### EC

```bash
### Gen ECC
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --keypairgen \
  --key-type EC:secp256r1 \
  --id 02 \
  --label "My ECC Key" \
  --usage-sign --usage-decrypt

### Sign
#### Listando mecanismos de assinatura.
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so   --login --pin 0000   --sign   --id 02   --list-mechanism
#### Hash it first
sha256sum data.txt | awk '{print $1}' > data.txt.sha256_hex
xxd -r -p data.txt.sha256_hex > data.txt.sha256_binary
#### Sign
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --sign \
  --id 02 \
  --mechanism ECDSA \
  --input-file data.txt.sha256_binary \
  --output-file data.eccsig \
  --signature-format openssl

### Verify
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --verify \
  --id 02 \
  --mechanism ECDSA \
  --input-file data.txt.sha256_binary \
  --signature-file data.eccsig \
  --signature-format openssl

```

### EdDSA

```bash
### Gen EdDSA
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --keypairgen \
  --key-type EC:edwards25519 \
  --id 03 \
  --label "My EdDSA Key" \
  --usage-sign

### Sign
# No pre-hashing is needed for EdDSA as it's part of the algorithm itself.
# Pass the original file directly.
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --sign \
  --id 03 \
  --mechanism EDDSA \
  --input-file data.txt \
  --output-file data.eddsasig

### Verify
pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --verify \
  --id 03 \
  --mechanism EDDSA \
  --input-file data.txt \
  --signature-file data.eddsasig
```
