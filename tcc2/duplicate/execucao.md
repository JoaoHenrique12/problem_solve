- log level
- Alterar pkcs ?


root@8cc15b6ec79d:/app# cat /var/log/syslog 
Sep  4 23:44:54 8cc15b6ec79d syslog.info syslogd started: BusyBox v1.36.1
Sep  4 23:45:18 8cc15b6ec79d user.err pkcs11-tool: OSSLCryptoFactory.cpp(363): Unknown algorithm '7'


syslogd -n -O /var/log/syslog &

pkcs11-tool --module /usr/local/lib/softhsm/libsofthsm2.so \
  --login --pin 0000 \
  --keypairgen \
  --key-type EC:edwards25519 \
  --id 03 \
  --label "My EdDSA Key" \
  --usage-sign

Using slot 0 with a present token (0x2f50b015)
error: PKCS11 function C_GenerateKeyPair failed: rv = CKR_GENERAL_ERROR (0x5)
Aborting.


Gerando a chave
- CKM_EC_EDWARDS_KEY_PAIR_GEN

CK_RV SoftHSM::generateSLH

```cpp
	// Get the session
	// Get the token
	// Extract desired key information
	// pPublicKeyTemplate -> aqui aparece um monte de info importante.
	// CreateObject
	// ec->recycleKeyPair(kp);
	// CryptoFactory::i()->recycleAsymmetricAlgorithm(ec);
```
