```cpp
// Softhsm.h

	// A list with the supported mechanisms
	std::map<std::string, CK_MECHANISM_TYPE> mechanisms_table;
	std::list<CK_MECHANISM_TYPE> supportedMechanisms;
	CK_ULONG nrSupportedMechanisms;
  //
	CK_RV generateED
	(
		CK_SESSION_HANDLE hSession,
		CK_ATTRIBUTE_PTR pPublicKeyTemplate,
		CK_ULONG ulPublicKeyAttributeCount,
		CK_ATTRIBUTE_PTR pPrivateKeyTemplate,
		CK_ULONG ulPrivateKeyAttributeCount,
		CK_OBJECT_HANDLE_PTR phPublicKey,
		CK_OBJECT_HANDLE_PTR phPrivateKey,
		CK_BBOOL isPublicKeyOnToken,
		CK_BBOOL isPublicKeyPrivate,
		CK_BBOOL isPrivateKeyOnToken,
		CK_BBOOL isPrivateKeyPrivate
	);
```

```cpp
// Softhsm.cpp
static CK_RV newP11Object(CK_OBJECT_CLASS objClass, CK_KEY_TYPE keyType, CK_CERTIFICATE_TYPE certType, P11Object **p11object)
void SoftHSM::prepareSupportedMechanisms(std::map<std::string, CK_MECHANISM_TYPE> &t)
CK_RV SoftHSM::C_GetMechanismInfo(CK_SLOT_ID slotID, CK_MECHANISM_TYPE type, CK_MECHANISM_INFO_PTR pInfo)
CK_RV SoftHSM::AsymSignInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
CK_RV SoftHSM::AsymVerifyInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
CK_RV SoftHSM::C_GenerateKeyPair
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_ATTRIBUTE_PTR pPublicKeyTemplate,
	CK_ULONG ulPublicKeyAttributeCount,
	CK_ATTRIBUTE_PTR pPrivateKeyTemplate,
	CK_ULONG ulPrivateKeyAttributeCount,
	CK_OBJECT_HANDLE_PTR phPublicKey,
	CK_OBJECT_HANDLE_PTR phPrivateKey
)


AsymmetricAlgorithm* eddsa = CryptoFactory::i()->getAsymmetricAlgorithm(AsymAlgo::EDDSA);

CKF_GENERATE_KEY_PAIR
```
