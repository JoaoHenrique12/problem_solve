# Duplicate

## Notes

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

## CMakeList.txt ?
