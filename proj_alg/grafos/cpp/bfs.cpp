// URI 1799
#include <bits/stdc++.h>

using namespace std;
#define max 4050

vector<int>G[max];

int distancia[max];

void bfs(int ini) {
    memset(distancia, -1, sizeof distancia);
    int initial_vertice = ini;
    queue<int> to_visit;
    to_visit.push(initial_vertice);
    distancia[initial_vertice] = 0;

    while(!to_visit.empty()) {
        auto u = to_visit.front();
        to_visit.pop();

        for (auto v: G[u]) {
            if (distancia[v] == -1) {
                distancia[v] = distancia[u] + 1;
                to_visit.push(v);
            }
        }
    }
}


int main() {
  int v,a,step=0;
  char n1[10],n2[10];
  unordered_map<string,int>mapa;

  scanf("%d %d\n",&v,&a);

  mapa["Entrada"] = 0;
  mapa["Saida"] = v;

  while(a--){//Entrada = 0 Saida = v-1
    scanf("%s %s\n",n1,n2);
    if (mapa.find(n1)==mapa.end()) {
      mapa[n1] = mapa.size()-1;
    }
    if (mapa.find(n2)==mapa.end()) {
      mapa[n2] = mapa.size()-1;
    }
    G[mapa[n1]].push_back(mapa[n2]);
    G[mapa[n2]].push_back(mapa[n1]);
  }
  bfs(mapa["Entrada"]);
  step = distancia[mapa["*"]];
  //printf("Way1 %d\n",step);

  bfs(mapa["*"]);
  //printf("Way2 %d\n",distancia[mapa["Saida"]]);
  step =step + distancia[mapa["Saida"]];

	//for(auto a : mapa)
	//	printf("key %s value %d\n",a.first.c_str(),a.second);
  printf("%d\n",step );
  return 0;
}
