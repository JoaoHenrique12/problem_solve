/*
 * gcc -o pkcs11-sphincsp pkcs11-sphincsp.c -ldl
 * 
 * Updates to be made within this source file:
 * Replace the text <so-user-api-key> with the SO user's PIN.
 * Replace the text <normal-user-api-key> with the normal user's PIN.
 * Replace the text <pkcs11-library> with name of your pkcs11 library.
 * 
 * Ensure that your pkcs11 library is in your library path (LD_LIBRARY_PATH)
 * and the grep11client.yaml PKCS11 configuration file is in the /etc/ep11client directory. You may
 * need to create the /etc/ep11client directory, if it does not exist.
 *
 * NOTE: This sample code is expecting a default library name of pkcs11-grep11.so (See the pkcs11LibName variable).
 *       Feel free to change the name to match your pkcs11 library name.
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <dlfcn.h>
#include <sys/timeb.h>
#include "sample.h"

CK_FUNCTION_LIST  *funcs;
CK_BYTE           tokenNameBuf[32];
const char        tokenName[] = "meulabel";

#define DUMP_HEXA(A, B)		\
					do {	\
						printf("%s[%d]: \n", (char *) #A, (int) B);	\
						dump_hexa((const void*) A, (size_t) B); 	\
					} while(0) 

void dump_hexa(const void* data, size_t size) {
	char ascii[17];
	size_t i, j;
	ascii[16] = '\0';
	for (i = 0; i < size; ++i) {
		printf("%02X ", ((unsigned char*)data)[i]);
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
			ascii[i % 16] = ((unsigned char*)data)[i];
		} else {
			ascii[i % 16] = '.';
		}
		if ((i+1) % 8 == 0 || i+1 == size) {
			printf(" ");
			if ((i+1) % 16 == 0) {
				printf("|  %s \n", ascii);
			} else if (i+1 == size) {
				ascii[(i+1) % 16] = '\0';
				if ((i+1) % 16 <= 8) {
					printf(" ");
				}
				for (j = (i+1) % 16; j < 16; ++j) {
					printf("   ");
				}
				printf("|  %s \n", ascii);
			}
		}
	}
}


int main( int argc, char **argv )
{
   CK_C_INITIALIZE_ARGS  initArgs;
   CK_RV                   rc;
   CK_FLAGS                flags = 0;
   CK_SESSION_HANDLE       session;
   CK_MECHANISM            mech;
   CK_OBJECT_HANDLE        publicKey, privateKey, aesKey;
   static CK_BBOOL         isTrue = TRUE;
   static CK_BBOOL         isFalse = FALSE;
   CK_BYTE id[] = {123};
   CK_UTF8CHAR_PTR keyLabel = (unsigned char *) "pqlabel";

   CK_RV                   (*pFunc)();
   void                    *pkcs11Lib;
   CK_UTF8CHAR_PTR         soPin = (unsigned char *) "66666";
   CK_UTF8CHAR_PTR         userPin = (unsigned char *) "4444";
   char                    pkcs11LibName[] = "libsofthsm2.so";
 
   printf("Opening the PKCS11 library...\n");
   //pkcs11Lib = dlopen(pkcs11LibName, RTLD_NOW);
   pkcs11Lib = dlopen(pkcs11LibName, RTLD_LAZY);
   if ( pkcs11Lib == NULL ) {
      printf("%s not found. Ensure that the PKCS11 library is in the system library path or LD_LIBRARY_PATH\n", pkcs11LibName);
      return !CKR_OK;
   }
 
   printf("Getting the PKCS11 function list...\n");
   pFunc = (CK_RV (*)())dlsym(pkcs11Lib, "C_GetFunctionList");
   if (pFunc == NULL ) {
      printf("C_GetFunctionList() not found in module %s\n", pkcs11LibName);
      return !CKR_OK;
   }
   rc = pFunc(&funcs);
   if (rc != CKR_OK) {
      printf("error C_GetFunctionList: rc=0x%04lx\n", rc );
      return !CKR_OK;
   }
 
   printf("Initializing the PKCS11 environment...\n");
   memset( &initArgs, 0x0, sizeof(initArgs) );
   rc = funcs->C_Initialize( &initArgs );
   if (rc != CKR_OK) {
      printf("error C_Initialize: rc=0x%04lx\n", rc );
      return !CKR_OK;
   }
   
	CK_SLOT_ID available_slots[10];
	CK_ULONG num_slots = 10;

	rc = funcs->C_GetSlotList(1, available_slots, &num_slots);
	if (rc != CKR_OK) {
		printf("Failed to get the available slots: rc=0x%04lx\n", rc);
		return 0;
	}
	
	printf("Available slots: 0x%04lx %d\n", available_slots[0], num_slots);
	
   printf("Initializing the token... \n");
   memset(tokenNameBuf, ' ', sizeof(tokenNameBuf)); /* Token name is left justified, padded with blanks */
   memcpy(tokenNameBuf, tokenName, strlen(tokenName));

   /* C_InitToken cleans up private and public keystore thus only needs to be done once.
    * Subsequent C_InitToken calls will delete any existing keys within the keystores
    */
   rc= funcs->C_InitToken(available_slots[0], soPin, strlen((const char *) soPin), tokenNameBuf);
   if (rc != CKR_OK) {
      printf("error C_InitToken: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
 
   flags = CKF_SERIAL_SESSION | CKF_RW_SESSION;
   printf("Opening a session... \n");
   rc = funcs->C_OpenSession( available_slots[0], flags, (CK_VOID_PTR) NULL, NULL, &session );
   if (rc != CKR_OK) {
      printf("error C_OpenSession: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
   
   
   printf("Logging in as SO... \n");
   rc = funcs->C_Login( session, CKU_SO, soPin, strlen((const char *) soPin));
   if (rc != CKR_OK) {
      printf("error C_Login: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
   
   printf("Initing normal user pin... \n");
   rc = funcs->C_InitPIN( session, userPin, strlen((const char *) userPin));
   if (rc != CKR_OK) {
      printf("error C_InitPin: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
   
   rc = funcs->C_Logout(session);
   if (rc != CKR_OK) {
      printf("error C_Logout: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
 
   printf("Logging in as normal user... \n");
   rc = funcs->C_Login( session, CKU_USER, userPin, strlen((const char *) userPin));
   if (rc != CKR_OK) {
      printf("error C_Login: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }

   // Use Sphincsp key to sign & verify
   printf("Generating Sphincsp key pair... \n");
   /* Attributes for the public key to be generated */
   CK_KEY_TYPE keyType = CKK_PQC_SPHINCSP;
   // TODO: MUDAR PARA O OID CORRETO DO SPHINCS+
   CK_BYTE sphincsp[] = {0x06, 0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x07, 0x06, 0x05};
   CK_ATTRIBUTE pub_tmpl[] = {
      {CKA_TOKEN,           &isTrue, sizeof(isTrue) },
      {CKA_PQC_PARAMS,  &sphincsp,   sizeof(sphincsp) },
      {CKA_VERIFY,          &isTrue,  sizeof(isTrue) },
      {CKA_KEY_TYPE,        &keyType, sizeof(keyType) },
      {CKA_ID, id, sizeof(id)},
      {CKA_LABEL, keyLabel, strlen(keyLabel)},
   };
 
   /* Attributes for the private key to be generated */
   CK_ATTRIBUTE priv_tmpl[] =
   {
      {CKA_TOKEN,           &isTrue, sizeof(isTrue) },
      {CKA_SIGN,            &isTrue, sizeof(isTrue) },
      {CKA_EXTRACTABLE,     &isFalse,  sizeof(isFalse) },
      {CKA_KEY_TYPE,        &keyType, sizeof(keyType) },
      {CKA_ID, id, sizeof(id)},
      {CKA_LABEL, keyLabel, strlen(keyLabel)},
   };
   mech.mechanism      = CKM_PQC_SPHINCSP;
   mech.ulParameterLen = 0;
   mech.pParameter     = NULL;
 
   rc = funcs->C_GenerateKeyPair( session,   &mech,
                                  pub_tmpl,   sizeof(pub_tmpl)/sizeof(CK_ATTRIBUTE),
                                  priv_tmpl,  sizeof(priv_tmpl)/sizeof(CK_ATTRIBUTE),
                                  &publicKey, &privateKey );
   if (rc != CKR_OK) {
      printf("error C_GenerateKeyPair: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }

   printf("Signing with Sphincsp private key... \n");
   CK_BYTE dataToBeSigned[] = "This is data to be signed";
   CK_ULONG dataToBeSignedLen = sizeof(dataToBeSigned) - 1;
   CK_BYTE signature[10240];
   CK_ULONG signatureLen = sizeof(signature);

   mech.mechanism      = CKM_PQC_SPHINCSP;
   mech.ulParameterLen = 0;
   mech.pParameter     = NULL;

   rc = funcs->C_SignInit(session, &mech, privateKey);
   if (rc != CKR_OK) {
      printf("error C_SignInit: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }

   rc = funcs->C_Sign(session, dataToBeSigned, dataToBeSignedLen, signature, &signatureLen);
   if (rc != CKR_OK) {
      printf("error C_Sign: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
   
   DUMP_HEXA(signature, signatureLen);


   printf("Verifying with Sphincsp public key... \n");
   rc = funcs->C_VerifyInit(session, &mech, publicKey);
   if (rc != CKR_OK) {
      printf("error C_VerifyInit: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
   
   rc = funcs->C_Verify(session, dataToBeSigned, dataToBeSignedLen, signature, signatureLen);
   if (rc != CKR_OK) {
      printf("error C_Verify: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
   
#if 1

   dataToBeSigned[10] ^= dataToBeSigned[10];
   printf("Must fail! \n");

   printf("Verifying with Sphincsp public key... \n");
   rc = funcs->C_VerifyInit(session, &mech, publicKey);
   if (rc != CKR_OK) {
      printf("error C_VerifyInit: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }
   
   rc = funcs->C_Verify(session, dataToBeSigned, dataToBeSignedLen, signature, signatureLen);
   if (rc != CKR_OK) {
      printf("error C_Verify: rc=0x%04lx (AS EXPECTED!!!!)\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }

#endif


   printf("Logging out... \n");
   rc = funcs->C_Logout(session);
   if (rc != CKR_OK) {
      printf("error C_Logout: rc=0x%04lx\n", rc );
      funcs->C_Finalize( NULL );
      return !CKR_OK;
   }

   printf("Closing the session... \n");
   rc = funcs->C_CloseSession( session );
   if (rc != CKR_OK) {
      printf("error C_CloseSession: rc=0x%04lx\n", rc );
      return !CKR_OK;
   }

   printf("Finalizing... \n");
   rc = funcs->C_Finalize( NULL );
   if (rc != CKR_OK) {
      printf("error C_Finalize: rc=0x%04lx\n", rc );
      return !CKR_OK;
   }
   printf("Sample completed successfully!\n");
   return 0;
}
