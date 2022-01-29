// URI 1082
#include<bits/stdc++.h>
using namespace std;
#define max 26

vector<int>base[max];

bool visited[max];

void dfs(int v){
    visited[v] = true;

    for(auto i:base[v]){
        if(!visited[i]) 
            dfs(i);
    }

}
int main() {
    memset(visited,0,sizeof visited);
    int aux;
    for(int aux=0;aux<max;aux++){
            base[aux].clear();
    } 
    int caso,ver,ar;
    char partida, chegada;
    scanf("%d",&caso);
    scanf("%d %d\n",&ver,&ar);
    int k,j;
    for(int k = 1;k<=caso;k++){
        bool jp[max];
        memset(jp,0,sizeof jp);
        memset(visited,0,sizeof visited);
        for(int aux =0;aux<ar;aux++){//Grafo preenchido
            //bool repetiu =0;
            scanf("%c %c",&partida,&chegada);
            getchar();//pega o \n
            partida-=97;
            chegada-=97;
            /*for(int aux=0;aux<base[partida].size();aux++){//garante apenas a ida
                if(base[partida][aux]==chegada){
                    repetiu = 1;
                    break;
                }
            }*/
            //if (repetiu) continue;
            base[chegada].push_back(partida);
            base[partida].push_back(chegada);
        }//final leitura
        printf("Case #%d:\n",k);
        int con =0;
        for(int aux =0;aux<ver;aux++){//Grafo preenchido
            dfs(aux);
            bool entrei = false;
            for(j=0;j<max;j++){
                if(visited[j] && !jp[j]){
                    printf("%c,",j+97);
                    jp[j] = true;
                    entrei = true;
                }
            }
            if(entrei){
                con++;
                printf("\n");
            }
        }
        printf("%d connected components",con);
        printf("\n\n");
        for(int aux=0;aux<max;aux++){
            base[aux].clear();
        }
        if(k!=caso){
            scanf("%d %d\n",&ver,&ar);
        }
    }

    return 0;
}