// #URI1148
#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
#define INF numeric_limits<int>::max() - 10
#define MAX_V 501
vector<ii> G[MAX_V];
int distances[MAX_V];
int N,M;

void fill()
{
  for( int i = 0; i < N + 1; i++)
    distances[i] = INF;
}
int dijkstra(int src, int dest)
{
  fill();
  distances[src] = 0;
  priority_queue<ii,vector<ii>,greater<ii>> to_visit;
  to_visit.push(ii(distances[src],src));

  while(!to_visit.empty())
  {
    auto [ d ,v ] = to_visit.top();
    to_visit.pop();
    if( d > distances[v] ) continue;
    for( auto i : G[v] )
    {
      auto [ i_d, i_v ] = i;
      if( distances[v] + i_d < distances[i_v] ) 
      {
        distances[i_v] = distances[v] + i_d;
        to_visit.push({distances[i_v],i_v});
      }
    }
  }
  return distances[dest];
}

int main()
{

  int x,y,p;
  int test_cases;
  while( scanf("%d %d",&N,&M),N || M)
  {
    for(int i = 0; i < N; i++)
      G[i].clear();
    for(int i = 0; i < M; i++)
    {
      scanf("%d %d %d",&x,&y,&p);
      x--;y--;
      bool double_edge = false;
      for(auto& k : G[y])
      {
        auto& [p,aresta] = k;
        if( aresta == x )
        {
          double_edge = true;
          G[x].push_back({0,y});
          p = 0;
        }
      }
      if(!double_edge)
        G[x].push_back({p,y});
    }
    scanf("%d",&test_cases);
    int dist;
    while(test_cases--)
    {
      scanf("%d %d",&x,&y);
      x--;y--;
      dist = dijkstra(x,y);
      if( dist == INF )
        printf("Nao e possivel entregar a carta\n");
      else
        printf("%d\n",dist);
    }
    printf("\n");
  }
  return 0;
}
