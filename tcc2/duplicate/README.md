# Duplicate

## Notes

### DER (Distinguished Encoding Rules)

https://letsencrypt.org/docs/a-warm-welcome-to-asn1-and-der/

PKCS#8 DER é o formato binário e serializado para armazenar informações de chaves privadas criptográficas, parte da norma PKCS#8,
que pode ser opcionalmente criptografada com uma palavra-passe usando um dos esquemas PKCS#5. DER (Distinguished Encoding Rules)
é um método de codificação binário para dados usando ASN.1, que é uma representação alternativa ao formato PEM 
(Privacy-Enhanced Mail). 

### Notes

nid -> New ID, é o id na hora de criar as chaves com o ctx !!!
PTAL -> NID_ED25519

INICIALMENTE DUPLICAR COM OUTRO NOME, APENAS, SEM NID.

- Substituir o NID pelo nome do algoritmo

## M4

```m4
acx_crypto_backend.m4
acx_openssl_slhds.m4
```

## SLH(Private|Public)Key.(cpp|h)

Aonde são usadas as funções definidas aqui ?

## OSSLSLH(Public|Private)Key.(cpp|h)

Especialização de classe dos arquivos anteriores.

A pergunta anterior se propaga aqui.

Aqui aparece NID, e funções específicas, na hora de implementar
SLH-DSA estes arquivos vão precisar de mais atenção.

Representação OSSL.

## OSSLSLHKeyPair.(cpp|h)

Estes arquivos foram simpes, nem vai precisar de mexer nele na parte
de implementacao do SLH-DSA.

## OSSLEDDSA.(cpp|h)

Aqui ele usa os parâmetros de curva elíptica. Vou precisar de criar um próprio pra SLH-DSA ?

ECParameters.(cpp|h)

### Definido novo mecanismo

```cpp
// AsymetricAlgorithm.h
struct AsymAlgo
{
        enum Type
	{
		EDDSA,
		SLHDSA
  };
};
// ----

struct AsymMech
{
	enum Type
	{
		EDDSA,
		SLHDSA
  };
}
```

## OSSLCryptoFactory.cpp

Added SLHDSA -> OSSLCryptoFactory::getAsymmetricAlgorithm(...)...

## OSSLUtil.(cpp|h)

Apenas operações com NID, devo deletar o que dupliquei ou ajustar para usar strings ?

DER-encoded ASN.1 string, the function ensures that these curve identifiers can be consistently and portably used in cryptographic contexts,
such as storing them in a PKCS#11 token or communicating them between different cryptographic systems. This is particularly important for
edwards and curve types of elliptic curves, which are commonly used for digital signatures and key exchange, respectively.

Vou ter que definir as strings do SLH-DSA no pkcs11-tool ?

Duplicado com if defined() || defined()

procurar aonde são usadas:
```cpp
	ByteString oid2ByteString(int nid);
	int byteString2oid(const ByteString& byteString);
```
## crypto/CMakeLists.txt

Added the 6 *.cpp files of SLH-DSA
