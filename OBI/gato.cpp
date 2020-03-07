#include<bits/stdc++.h>

using namespace std;

int inf = 1e9 + 7;
vector<bool>muro;
int memo[10100];

int min_saltos(unsigned int lajota, int saltos)
{
  if( lajota == muro.size()-1 ) return 0;
  if( lajota >= muro.size() || muro[lajota] == 0 ) return inf;

  if( memo[lajota] == -1)
    return memo[lajota] =min(inf,( 1 + min(min_saltos(lajota+1,saltos+1),min_saltos(lajota+2,saltos+1))));
  else
    return memo[lajota];

}

int main()
{
  unsigned int lajotas;
  bool aux;

  memset(memo,-1,sizeof memo);

  cin >> lajotas;
  
  while(lajotas--)
  {
    cin >> aux;
    muro.push_back(aux);
  }
  int resp = min_saltos(0,0) == inf ? -1 : memo[0];
  cout << resp << endl;

  return 0;
}
