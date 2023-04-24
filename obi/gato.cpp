#include<bits/stdc++.h>

using namespace std;

int INF = 1e9 + 7;
const short NOT_SOLVED = -1;

vector<bool>muro;
int memo[10100];

int min_saltos(unsigned lajota, int saltos)
{
  if( lajota == muro.size()-1 ) return 0;

  if( lajota >= muro.size() || muro[lajota] == 0 ) return INF;

  if( memo[lajota] == NOT_SOLVED)
    return memo[lajota] = min(INF,( 1 + min(min_saltos(lajota+1,saltos+1),min_saltos(lajota+2,saltos+1))));
  else
    return memo[lajota];

}

int main()
{
  unsigned lajotas;
  bool aux;

  memset(memo,NOT_SOLVED,sizeof memo);

  cin >> lajotas;
  
  while(lajotas--)
  {
    cin >> aux;
    muro.push_back(aux);
  }
  int resp = min_saltos(0,0) == INF ? NOT_SOLVED : memo[0];
  cout << resp << endl;

  return 0;
}
/* Programa compilado com g++ usando as flags -std=c++11 -W
 *
 * O problema Saltos do gato trata-se de uma programação dinâmica, dado que a quantia de saltos minima
 * pode ser calculada através da tentativa do gato dar um salto de uma ou duas lajotas conseguintes de uma vez e verificar
 * qual tipo de salto é otimizado para reduzir o caminho diante das regras impostas, e em seguida repetir este processo até que chegue a lajota final.
 * 
 * Para evitar um Time Limit Exceed(TLE) é crucial utilizar também um array de memorização, o qual irá guardar
 * os subproblemas( se o salto otimizado é o de uma ou duas lajotas ).
 *
 * Variáveis principais: 
 * muro: vector de boolean que representa as lajotas pretas e brancas.
 * lajota: representa a posição do gato no muro.
 * lajotas: tamanho do muro.
 * memo: array com a memorização da melhor solução para cada posição do muro.
 * saltos: quantia de saltos que falta para o gato chegar a ultima lajota do muro.
 *
 * Função main:
 *  Possui a leitura dos dados e inicialização do array de memorização com o valor -1, que representa a não solução 
 *  do problema para a i-ésima posição do muro.
 * Função min_saltos:
 *  Nesta Função recursiva é realizada a passagem dos parâmetros lajota,saltos por valor.
 *  	Em seguida é verificado o caso base da DP( Dynamic Programming ), ou seja se o gato esta
 *  na última lajota, caso esteja, faltam 0 saltos para que ele chegue a útima lajota.
 *		Logo a baixo é verificado se o gato está a tentar pular para uma posição inválida, ou seja, para fora
 *	do muro ou em uma lajota de cor branca, caso isto ocorra, a quantia de saltos retornada é infinito, dado que o gato
 *	está a fazer um movimento inválido.
 *		Por conseguinte, é verificada a possibilidade do problema ja ter sido resolvido em alguma das chamadas da recursão
 *	no caso do problema já possuir uma resposta basta consultar o array de memorização. Caso contrário o fluxo de transição
 *	da DP será acionado.
 *		O estado de transição da DP consiste em calcular o menor caminho de saltos do gato até a ultima lajota, diante da opção do gato dar 
 *	um pulo de tamanho 1 ou 2. Portanto teremos que tirar o mínimo entre infinitos saltos e 1 salto + mínimo de saltos da decisão de dar um pulo de
 *	tamanho 1 ou 2.
 *  link: <https://olimpiada.ic.unicamp.br/pratique/pj/2018/f3/pulo/>
 */
