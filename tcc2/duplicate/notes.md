# Notes

Consegui apagar os arquivos do EDDSA e remover ele da listagem de mecanismos (jp-delete-eddsa).

Consegui fazer compilar o SLH-DSA em baixo do EDDSA com a duplicação de código (EDDSA -> SLH-DSA). (jp-duplicate-eddsa)

-> WITH_SLHDSA
-> Problemas: SLH-DSA não aceita NID; trocar parâmetros de ECC para os próprio SLH-DSA; adicionar id próprio para listagem.

sha: a0e0eced44f0d2c469a13958f5749a24c61099b4

Tomei o erro:
```
Using slot 0 with a present token (0xaa1b9a6)
error: PKCS11 function C_GenerateKeyPair failed: rv = CKR_GENERAL_ERROR (0x5)
Aborting.
```
