# Flow

## SoftSHM.C_GenerateKeyPair

```
// Get session
keyType <- switch(pMechanism->mechanism) {CKM_SLH_KEY_PAIR_GEN: CKK_SLHDSA}

// CKA_TOKEN extracted only (token value: isTrue)
extractObjectInformation(for public key)
validate(for public key)

// CKA_TOKEN extracted only (token value: isTrue)
extractObjectInformation(for private key)
validate(for private key)

// Check user credentials
generateSLH(pkTemplate, skTemplate, pkPointer, skPointer,...)

```

### SoftSHM.generateSLH

```
// Get session
// Get the token
// Extract desired key information (in this case: name 'SLH-DSA-SHA2-128s\0')

SLHParameters p; p.setName(params);

AsymmetricKeyPair* kp = NULL;
AsymmetricAlgorithm* slh = CryptoFactory::i()->getAsymmetricAlgorithm(AsymAlgo::SLHDSA);

slh->generateKeyPair(&kp, &p)


SLHPublicKey* pub = (SLHPublicKey*) kp->getPublicKey();
SLHPrivateKey* priv = (SLHPrivateKey*) kp->getPrivateKey();

```

#### OSSLSLHDSA.generateKeyPair

```
// check key pair and parameters
// get param name (SLHParams.getName)
// Create EVP_PKEY_CTX_new_from_name
// open context
// keygen

OSSLSLHKeyPair* internal_kp = new OSSLSLHKeyPair();
((OSSLSLHPublicKey*) internal_kp->getPublicKey())->setFromOSSL(pkey);
((OSSLSLHPrivateKey*) internal_kp->getPrivateKey())->setFromOSSL(pkey);
*ppKeyPair = internal_kp;

```
