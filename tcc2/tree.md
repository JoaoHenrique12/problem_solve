# Tree

## Mapped
```
entrypoint files: 
  acx_crypto_backend.m4
  acx_openssl_eddsa.m4
   src
  │  bin
  │ └  util
  │   │  softhsm2-util-ossl.cpp   ✗ 
  │   └  softhsm2-util-ossl.h     ✗ 
  └  lib
    │  crypto
    │ │  CMakeLists.txt           ✗ 
    │ │  ECParameters.cpp         ✗ 
    │ │  OSSLCryptoFactory.cpp    ✗ 
    │ │  OSSLEDDSA.cpp            ✗ 
    │ │  OSSLEDKeyPair.cpp        ✗ 
    │ │  OSSLEDPrivateKey.cpp     ✗ 
    │ │  OSSLEDPublicKey.cpp      ✗ 
    │ └  OSSLUtil.cpp             ✗ 
    │  pkcs11
    │ └  pkcs11.h                 ✗ 
    └  P11Objects.h               ✗ 
```

## First saw

### Primary ?
- src/lib/CMakelists.txt
  - src/lib/crypto/CMakelists.txt

- src/lib/crypto/OSSLEDDSA.h
- src/lib/crypto/OSSLEDKeyPair.h
- src/lib/crypto/OSSLEDPrivateKey.h
- src/lib/crypto/OSSLEDPublicKey.h

### Secondary ?
- lib/crypto/OSSLComp.cpp
- src/bin/dump/tables.h

### Terciary ?

- src/bin/util/softhsm2-util-ossl.h
eddsa_key_material_t

- src/bin/util/softhsm2-util-ossl.c
crypto_import_key_pair

### PTAL

```
Added on general
            EDPrivateKey.cpp
            EDPublicKey.cpp
--------------------------------------------------

                        OSSLECDH.cpp
                        OSSLECDSA.cpp
                        OSSLECKeyPair.cpp

                        OSSLECPrivateKey.cpp
                        OSSLECPublicKey.cpp


:eyes:
                        OSSLEDDSA.cpp
                        OSSLEDKeyPair.cpp
                        OSSLEDPrivateKey.cpp
                        OSSLEDPublicKey.cpp
:eyes:
```
