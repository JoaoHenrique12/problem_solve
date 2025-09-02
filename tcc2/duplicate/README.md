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
- SLH(Private|Public)Key
- OSSLSLH(Public|Private)Key
- OSSLSLHKeyPair
- OSSLEDDSA

## P11Objects.(cpp|h)

```cpp
//TODO:  Incomplete task, when add on pkcs11.h
// update CKK_EC_EDWARDS here either, both init fn.
```


### P11Attributes.(cpp|h)

PTAL -> Usa P11Attributes.h, que define, em algum lugar EC_PARAMS.

P11Attributes.h -> Mecanismos, atributos de EC.

P11Attributes.cpp

Search keys: CKA_EC_PARAMS, CKA_EC_POINT

L2220


Sem referencia a ED, EDDSA, EDWARDS.

### OSObjects.h

Nothing to do.

### pkcs11.h

Just a note, without direct import
CKK_ -> Key type
usa a definição (pkcs11.h -> CKK_EC_EDWARDS)

### Info

BaseClass is P11Object -> attributes map ?

```cpp
	std::map<CK_ATTRIBUTE_TYPE, P11Attribute*> attributes;
```

P11Object uses -> OSObject (object storage.)

P11EDPrivateKeyObj::init -> class P11SLHPrivateKeyObj : public P11PrivateKeyObj
P11EDPublicKeyObj::init -> class P11SLHPublicKeyObj : public P11PrivateKeyObj

#### P11ED(Public|Private)KeyObj::init

-> CKK_VENDOR_DEFINED, como fazer as minhas proprias definicoes ?
-> As definicoes de atributos de curva eliptica aparecem aqui.
```cpp
	// Create attributes
	P11Attribute* attrEcParams = new P11AttrEcParams(osobject,P11Attribute::ck3);
	P11Attribute* attrEcPoint = new P11AttrEcPoint(osobject);
```

## pkcs11.h

### Ideias

Duplicar as variaveis com os mesmos valores ? Pode ser que dê algum
conflito em algum lugar...

Adicionar novas variaveis e manter os apontamentos que EDDSA usa.
Resultaria em mais trabalho posterior.

### Constants found.

```cpp
// Curva eliptica:
#define CKA_ECDSA_PARAMS		(0x180UL)
#define CKA_EC_PARAMS			(0x180UL)
#define CKA_EC_POINT			(0x181UL)


/* From version 3.0 */
#define CKM_EC_EDWARDS_KEY_PAIR_GEN	(0x1055UL)
#define CKM_EDDSA			(0x1057UL)

#define CKK_EC_EDWARDS		(0x40UL)

```
#### CKA_ECDSA_PARAMS

É o mesmo valor dos parâmetros de EC_PARAMS.
Se eu for criar um específico para SLH_DSA vou ter que investigar
mais EC_PARAMS.

- DBObject.cpp

#### CKA_EC_PARAMS

Encontrado em diversos lugares:
- dump/tables.h
- SoftHSM.cpp
- P11Attributes
- util/softhsm2-util-ossl.cpp

#### CKM_EC_EDWARDS_KEY_PAIR_GEN | CKM_EDDSA

- dump/tables.h
- SoftHSM.cpp

#### CKK_EC_EDWARDS

- P11Objects.cpp
- SoftHSM.cpp
- dump/tables.h
- util/softhsm2-util-ossl.cpp

## softhsm2-util-ossl.(cpp|h)

no .h o cabecalho foi importado com: if defined() || defined()

```cpp
typedef struct eddsa_key_material_t {}

int crypto_save_eddsa(CK_SESSION_HANDLE hSession, char* label, char* objID, size_t objIDLen, int noPublicKey, EVP_PKEY* eddsa);
eddsa_key_material_t* crypto_malloc_eddsa(EVP_PKEY* eddsa);
void crypto_free_eddsa(eddsa_key_material_t* keyMat);
```

### softhsm2-util-ossl.cpp

```cpp
// Isso vai falhar, SLH-DSA não tem essa chamada por id.
// por hora vou manter, mas isso tem que ser ajustado.
switch (EVP_PKEY_type(EVP_PKEY_id(pkey)))
```

## SoftHSM.(cpp|h)

### SoftHSM.h

Não foi alterado, só tem uma definição de função de derivação de chave.

### SoftHSM.cpp

Existem 20 definições WITH_EDDSA :') .

- Definição de derivação de chave. (não alterado)
- Definição de geração de par de chave + mecanismo. (duplicado)
#### C_GetMechanismInfo
- Tem a definição de tamanho mínimo e máximo, não sei se mantem, por hora (duplicado) com
adição de variável para slhdsa.
- Ele faz isso na cryptofactory para adicionar o algoritmo ?
	CryptoFactory::i()->recycleAsymmetricAlgorithm(slhdsa); (duplicado)
- Derivação de chave (não alterado).
- switch case para inicialização de flags, aqui define de novo geração de par de chave + mecanismo +
flags de assinatura e verificação. (duplicado)
#### SoftHSM::AsymSignInit
- cria uma variável bool isSLHDSA (duplicado)
- switch case, ativa a variável caso CKM_* seja o dele e diz que não suporta assinatura multipart (duplicado)
- cria um if para verificar se esse que é o mecanismo usado tive que criar duas funções aqui (SoftHSM::getSLHPrivateKey,
SoftHSM::getSLHPublicKey) e adicionar no SoftHSM.h (import dos .h de pub/priv de SLH-DSA) 
(:thinking: colocaram o mesmo código para funções com nomes diferentes, por que ?).
#### SoftHSM::AsymVerifyInit
NOTA: Nem li o código ainda, mas acho que vai ser a mesma coisa que aconteceu no SignInit

Nota confirmada.
- ref 1 (duplicado)
- ref 2 (duplicado)
- ref 3 (duplicado)

#### SoftHSM::C_GenerateKeyPair

- case CKM_ key_type = CKK_EC_EDWARDS (duplicado)

#### SoftHSM::C_WrapKey

- case: não é usado para assinar/verificar (não alterado)
- outro case: (não alterado)

#### SoftHSM::C_UnwrapKey

- case: não é usado para assinar/verificar (não alterado)

#### SoftHSM::C_DeriveKey

- case: não é usado para assinar/verificar (não alterado)
#if defined(WITH_ECC) || defined(WITH_EDDSA)
		case CKM_ECDH1_DERIVE:
#endif

- outro case com ecc (não alterado)
  - tá dentro do case a cima (não alterado)

#### SoftHSM::deriveEDDSA

- Não é usado para assinar/verificar (não alterado)


#### Notas

CryptoFactory::i() -> retorna uma instancia (ossl|botan) de cryptofactor (singleton).
