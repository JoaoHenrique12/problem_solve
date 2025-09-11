# Compilation

```bash
export LD_LIBRARY_PATH=/usr/local/lib/softhsm:$LD_LIBRARY_PATH
cd /app/hpcs-pkcs11/samples/ && gcc pkcs11-slhdsa.c && cd /app && cp hpcs-pkcs11/samples/a.out .
./a.out data.txt
```
