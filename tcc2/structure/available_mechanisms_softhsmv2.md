# Available mechanisms with openssl 3.5.1

```
Supported mechanisms:
  AES-CBC, keySize={16,32}, encrypt, decrypt, wrap
  AES-CBC-ENCRYPT-DATA, derive
  AES-CBC-PAD, keySize={16,32}, encrypt, decrypt, wrap, unwrap
  AES-CMAC, keySize={16,32}, sign, verify
  AES-CTR, keySize={16,32}, encrypt, decrypt
  AES-ECB, keySize={16,32}, encrypt, decrypt
  AES-ECB-ENCRYPT-DATA, derive
  AES-GCM, keySize={16,32}, encrypt, decrypt
  AES-KEY-GEN, keySize={16,32}, generate
  AES-KEY-WRAP, keySize={16,2147483648}, wrap, unwrap
  mechtype-0x210A, keySize={1,2147483648}, wrap, unwrap
  CONCATENATE-BASE-AND-DATA, keySize={1,512}, derive
  CONCATENATE-BASE-AND-KEY, keySize={1,512}, derive
  CONCATENATE-DATA-AND-BASE, keySize={1,512}, derive
  DES2-KEY-GEN, generate
  DES3-CBC, encrypt, decrypt, wrap
  DES3-CBC-ENCRYPT-DATA, derive
  DES3-CBC-PAD, encrypt, decrypt, wrap, unwrap
  DES3-CMAC, sign, verify
  DES3-ECB, encrypt, decrypt
  DES3-ECB-ENCRYPT-DATA, derive
  DES3-KEY-GEN, generate
  DES-CBC, encrypt, decrypt, wrap
  DES-CBC-ENCRYPT-DATA, derive
  DES-CBC-PAD, encrypt, decrypt, wrap, unwrap
  DES-ECB, encrypt, decrypt, wrap
  DES-ECB-ENCRYPT-DATA, derive
  DES-KEY-GEN, generate
  DH-PKCS-DERIVE, keySize={512,10000}, derive
  DH-PKCS-KEY-PAIR-GEN, keySize={512,10000}, generate_key_pair
  DH-PKCS-PARAMETER-GEN, keySize={512,10000}, generate
  DSA, keySize={512,1024}, sign, verify
  DSA-KEY-PAIR-GEN, keySize={512,1024}, generate_key_pair
  DSA-PARAMETER-GEN, keySize={512,1024}, generate
  DSA-SHA1, keySize={512,1024}, sign, verify
  DSA-SHA224, keySize={512,1024}, sign, verify
  DSA-SHA256, keySize={512,1024}, sign, verify
  DSA-SHA384, keySize={512,1024}, sign, verify
  DSA-SHA512, keySize={512,1024}, sign, verify

-------------------------------------------------------------------------
  ECDH1-DERIVE, keySize={112,521}, derive
  ECDSA, keySize={112,521}, sign, verify, EC F_P, EC OID, EC uncompressed
  EC-EDWARDS-KEY-PAIR-GEN, keySize={255,448}, generate_key_pair
  ECDSA-KEY-PAIR-GEN, keySize={112,521}, generate_key_pair, EC F_P, EC OID, EC uncompressed
  EDDSA, keySize={255,448}, sign, verify
-------------------------------------------------------------------------

  GENERIC-SECRET-KEY-GEN, keySize={1,2147483648}, generate
  MD5, digest
  MD5-HMAC, keySize={16,512}, sign, verify
  MD5-RSA-PKCS, keySize={512,16384}, sign, verify
  RSA-PKCS, keySize={512,16384}, encrypt, decrypt, sign, verify, wrap, unwrap
  RSA-PKCS-KEY-PAIR-GEN, keySize={512,16384}, generate_key_pair
  RSA-PKCS-OAEP, keySize={512,16384}, encrypt, decrypt, wrap, unwrap
  RSA-PKCS-PSS, keySize={512,16384}, sign, verify
  RSA-X-509, keySize={512,16384}, encrypt, decrypt, sign, verify
  SHA1-RSA-PKCS, keySize={512,16384}, sign, verify
  SHA1-RSA-PKCS-PSS, keySize={512,16384}, sign, verify
  SHA224, digest
  SHA224-HMAC, keySize={28,512}, sign, verify
  SHA224-RSA-PKCS, keySize={512,16384}, sign, verify
  SHA224-RSA-PKCS-PSS, keySize={512,16384}, sign, verify
  SHA256, digest
  SHA256-HMAC, keySize={32,512}, sign, verify
  SHA256-RSA-PKCS, keySize={512,16384}, sign, verify
  SHA256-RSA-PKCS-PSS, keySize={512,16384}, sign, verify
  SHA384, digest
  SHA384-HMAC, keySize={48,512}, sign, verify
  SHA384-RSA-PKCS, keySize={512,16384}, sign, verify
  SHA384-RSA-PKCS-PSS, keySize={512,16384}, sign, verify
  SHA512, digest
  SHA512-HMAC, keySize={64,512}, sign, verify
  SHA512-RSA-PKCS, keySize={512,16384}, sign, verify
  SHA512-RSA-PKCS-PSS, keySize={512,16384}, sign, verify
  SHA-1, digest
  SHA-1-HMAC, keySize={20,512}, sign, verify
```
