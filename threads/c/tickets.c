#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define MAX_TICKETS 100
#define INVALID_TICKET -1
#define MAX_THREADS 5

sem_t mutex;
sem_t can_get_ticket;

size_t point_tickets = 0;
int tickets[MAX_TICKETS];

void init_tickets()
{
  point_tickets = 0;
  for(int i = 0; i < MAX_TICKETS; i++)
    tickets[point_tickets++] = 100 + i;
}

int get_ticket()
{
  sem_wait(&can_get_ticket);
  sem_wait(&mutex);

  int tk = tickets[--point_tickets];

  sem_post(&mutex);

  return tk;
}

void return_ticket(int ret)
{
  sem_wait(&mutex);

  tickets[point_tickets++] = ret;

  sem_post(&mutex);
  sem_post(&can_get_ticket);
}

void consumer(int mid)
{
  for( size_t i = 0; i < 20; i++ )
  {
    int tk = get_ticket();
    printf("Thread %d, ticket %d\n",mid,tk);
    //return_ticket(tk);
    //sleep(1);
  }
}

int main()
{
  sem_init(&mutex,0,1);
  sem_init(&can_get_ticket,0,MAX_TICKETS);

  init_tickets();

  pthread_t tid[MAX_THREADS];
  
  for(size_t i = 0; i < MAX_THREADS; i++)
    pthread_create(&tid[i], NULL, (void*) consumer, (void*) i ); 

  for(size_t i = 0; i < MAX_THREADS; i++)
    pthread_join(tid[i], NULL); 

  printf("point_tickets: %ld\n",point_tickets);
  return 0;
}


// Exercício: Implemente duas funções que possam ser usadas por THREADS COOPERANTES.
// A função get_ticket(), que retorna um inteiro positivo único para qualquer thread,
// e a função return_ticket(), que recebe "de volta" um ticket obtido pela função get_ticket().
