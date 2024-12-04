```bash
gcc main.c -fopenmp && time OMP_NUM_THREADS=100 cat file.md | ./a.out
```
