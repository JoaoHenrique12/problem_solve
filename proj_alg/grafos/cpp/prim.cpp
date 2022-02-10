// #URI1152
#include<bits/stdc++.h>
#define MAX_V 200005
#define oo  numeric_limits<int>::max();

using namespace std;
using ii = pair<int,int>;


int M,N;
vector<ii>G[MAX_V];

int distances[MAX_V];
bool visited[MAX_V];

long prim()
{
  priority_queue<ii,vector<ii>,greater<ii>>Q;
  for( int i = 0; i < N; i++) 
  {
    distances[i] = oo;
    visited[i] = false;
  }
  Q.push({0,0}); // Comeca no no 0 e a distancia ate ele e 0.
  distances[0] = 0;

  while(!Q.empty())
  {
    int u = Q.top().second;Q.pop();
    visited[u] = true;

    for( auto [p,v] : G[u] )
    {
      if( !visited[v] && p < distances[v])
      {
        Q.push({p,v});
        distances[v] = p;
      }
    }
  }
  long sum = 0;
  for( int i = 0; i < N; i++)
    sum += distances[i];

  return sum;
}
void printi()
{
  printf("printi\n");
  for(int i=0;i<N;i++)
  {
    printf("%d:",i);
    for(auto [p,u]:G[i])
      printf(" %d(%d)",u,p);
    printf("\n");
  }
}

int main()
{
  int x,y,p,tot;
  while( scanf("%d %d",&N,&M), N || M )
  {
    for( int i = 0; i < N; i++)
      G[i].clear();
    tot = 0;
    for( int i = 0; i < M; i++)
    {
      scanf("%d %d %d",&x,&y,&p);
      G[x].push_back({p,y});
      G[y].push_back({p,x});
      tot += p;
    }
//    printi();
    long sum = prim();
    printf("%ld\n",tot - sum);
  }
  return 0;
}
