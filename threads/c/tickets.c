#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_TICKETS 100
#define INVALID_TICKET -1

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
  if( point_tickets < 0 )
    return INVALID_TICKET;

  return tickets[--point_tickets];
}

void return_ticket(int ret)
{
  tickets[point_tickets++] = ret;
}


int main()
{

  return 0;
}


// Exercício: Implemente duas funções que possam ser usadas por THREADS COOPERANTES.
// A função get_ticket(), que retorna um inteiro positivo único para qualquer thread,
// e a função return_ticket(), que recebe "de volta" um ticket obtido pela função get_ticket().
