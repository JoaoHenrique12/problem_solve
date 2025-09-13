# Run

## Build
```bash
docker run -it -v "$(pwd):/app" soft_replic

# Logs
syslogd -n -O /var/log/syslog &

# Complete
sh autogen.sh
./configure --with-objectstore-backend-db --disable-gost --disable-eddsa --enable-slhdsa --with-crypto-backend=openssl
# Short version
make && make install
```

## NeoTest

```bash
export LD_LIBRARY_PATH=/usr/local/lib/softhsm:$LD_LIBRARY_PATH
cd /app/hpcs-pkcs11/samples/ && gcc pkcs11-slhdsa.c && cd /app && cp hpcs-pkcs11/samples/a.out .
./a.out data.txt
```

## Test

```bash
echo "msg" > data.txt

pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --keypairgen \
  --key-type EC:edwards25519 \
  --id 03 \
  --label "My EdDSA Key" \
  --usage-sign

pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --sign \
  --id 03 \
  --mechanism EDDSA \
  --input-file data.txt \
  --output-file data.eddsasig

pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --verify \
  --id 03 \
  --mechanism EDDSA \
  --input-file data.txt \
  --signature-file data.eddsasig
```
