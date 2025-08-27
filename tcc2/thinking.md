# Notes

NID_ED448 ?

#ifdef WITH_EDDSA

Create a class to heir from AsymmetricParameters.

nid -> New ID, é o id na hora de criar as chaves com o ctx !!!

# Sign/Verify


Serializable.h 
-> (Public|Private)key.h 
-> AsymmetricKeyPair.h | AsymmetricParameters.h | RNG.h
-> AsymmetricAlgorithm.h
-> OSSLEDDSA.h


# Key Pairs

## Info

public: ec, a
private: ec, k

## Files

PrivateKey.h
-> EDPrivateKey.h
-> OSSLEDPrivateKey.h

PublicKey.h
-> EDPublicKey.h
-> OSSLEDPublicKey.h


OSSLED(Public|Private)Key.h
-> OSSLEDKeyPair

# Register PKCS11

Must update the pkcs client either.

## cryptoki.h

Add 
```c
// They must be unique, update this decimal values later
#define CKK_SLH_DSA		(0x40UL)
#define CKM_SLH_DSA   (0x550UL)
```

## P11Objects

P11EDPublicKeyObj
P11EDPrivateKeyObj

## Files
OSAttribute(s).h | cryptoki.h | pkcs11.h
-> OSObject.h
-> P11Objects.h
-> SoftHSM.h (olhar mais)


softhsm2-util-ossl.h
