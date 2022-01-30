#include<bits/stdc++.h>
using namespace std;

#define MAX_V 500

vector<int>G[MAX_V];
bool visited[MAX_V];

int list_cycle[MAX_V];
int size_list_cycle = 0;
int init_cycle = 0;

bool cycle = false;

bool dfs(int u, int parent)
{
  bool is_cycle = false;
  visited[u] = true;
  list_cycle[size_list_cycle++] = u;
  for(int v: G[u])
  {
    if( visited[v] )
    {
      for( int i = 0 ; (i < size_list_cycle) && (size_list_cycle > 2) ; i++ )
        if(list_cycle[i] == v && v != parent)
        {
          init_cycle = i;
          cycle = true;
          list_cycle[size_list_cycle++] = v;
          return true;
        }
    }else
    { 
      is_cycle = dfs(v,u);
      if(is_cycle) 
        return true;
    }
  }
  size_list_cycle--;
  return is_cycle;
}

int main()
{
  memset(visited, sizeof visited, false);
  memset(list_cycle, sizeof list_cycle, 0);
  int n,m;
  int u,v;
  scanf("%d %d\n",&n,&m);
  for( int i = 0; i < m; i++ )
  {
    scanf("%d %d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int i = 0;
  while(dfs(i,i) != true && i < n)
    i++;

  if( i < n )
  {
    for( i = init_cycle; i < size_list_cycle - 1; i++ )
      printf("%d -> ",list_cycle[i]);
    printf("%d\n",list_cycle[i]);
  }else
    printf("Sem ciclo!!");

  return 0;
}
