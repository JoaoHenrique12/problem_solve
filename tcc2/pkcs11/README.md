# PKCS\#11
- [ibm-pkcs](https://github.com/IBM-Cloud/hpcs-pkcs11)
- [ibm-oqs](https://www.ibm.com/docs/en/zos/2.5.0?topic=management-quantum-safe-cryptography)
- [aws-pkcs11-sign](https://github.com/aws-samples/aws-cloudhsm-pkcs11-examples/tree/master/src/sign)
- [aws-pkcs11](https://github.com/aws-samples/aws-cloudhsm-pkcs11-examples)

## CONSTS

### Sugestao

Definir chave PQC_SPHINCSP: #define CKK_PQC_SPHINCSP      (0x80010037UL)
Definir atributos PQC: #define CKA_PQC_PARAMS (0x80000030UL)
Definir mecanismo: #define CKM_PQC_SPHINCSP (0x80010003UL)
Definir um erro próprio: #define CKR_PQC_PARAMS_NOT_SUPPORTED ((unsigned long)(CKR_VENDOR_DEFINED +0x10037))

#define CKK_PQC_SPHINCSP      (0x80010037UL)
#define CKA_PQC_PARAMS (0x80000030UL)
#define CKM_PQC_SPHINCSP (0x80010003UL)
#define CKR_PQC_PARAMS_NOT_SUPPORTED ((unsigned long)(CKR_VENDOR_DEFINED +0x10037))

### My

NOTE: softhsm2-util-ossl -> CKA_EC_POINT, vish.
P11Attributes.h -> P11AttrEcParams


CKK_EC_EDWARDS -> CKK_SLHDSA
CKA_EC_PARAMS -> CKA_SLHDSA_PARAMS

CKM_EC_EDWARDS_KEY_PAIR_GEN -> CKM_SLH_KEY_PAIR_GEN
CKM_EDDSA -> CKM_SLHDSA


```

	\item alteração nos arquivos \path{src/lib/P11Objects.(cpp|h)}; \path{P11SLHPublicKeyObj}, \path{P11SLHPrivateKeyObj} são as classes adicionadas;
		\path{ECParameters} aparece aqui novamente, também aparece uma constante do PKCS\#11, \path{CKK_EC_EDWARDS}; nas próximas atualizações
		ela será substituida por \path{CKK_SLHDSA} 


	\item alteração nos arquivos \path{src/bin/util/softhsm2-util-ossl.(cpp|h)}; aqui são definidas as funções de alocação/desalocação e salvamento do
		novo objeto no PKCS\#11; aqui aparece a constante \path{CKA_EC_PARAMS}, ela será substituida por \path{CKA_SLHDSA_PARAMS} 


	\item alteração no arquivo \path{src/lib/SoftHSM.cpp}; \path{prepareSupportedMechanisms} atualizado, adicionando \path{CKM_EC_EDWARDS_KEY_PAIR_GEN}
		e \path{CKM_EDDSA} na tabela de mecanismos; estas constantes serão substituidas por \path{CKM_SLH_KEY_PAIR_GEN} e \path{CKM_SLHDSA}; atualização nos métodos
		de assinatura e verificação, adicionando suporte ao SLH-DSA; métodos \path{getSLHPrivateKey}, \path{getSLHPublicKey} adicionados;
```
