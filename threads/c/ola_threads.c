#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<unistd.h>

// incluir -lpthread

typedef struct {
  int x;
  int ans;
}parametros;

int funcao(parametros* p)
{
  printf("Thread %d\n",p->x);
  while(1);

}

int main()
{
  pthread_t tid;
  parametros pr;
  pr.x = 500;

  pthread_create(&tid, NULL, (void*)funcao, &pr);
  printf("Thread criada\n");

  sleep(50);
  pthread_join(tid,NULL);

  return 0;
}
