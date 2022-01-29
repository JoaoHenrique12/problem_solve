/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: hellsank
 *
 * Created on September 24, 2018, 1:10 PM
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_V 1024

char G[MAX_V][MAX_V];

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, -1, 1};

int flood_fill(int x, int y, char color, char new_color,int N,int M) {

    if (x < 0 || y < 0 || x >= N || y >= M) return 0;
    if (G[x][y] != color) return 0;

    int vertice_count = 1;
    G[x][y] = new_color;

    for (int i = 0; i < 4; ++i)
        vertice_count += flood_fill(x + dx[i], y + dy[i], color, new_color,N,M);

    return vertice_count;
}

int main() {
    memset(G, 0, sizeof G);
    int l,c;
    char k;
    scanf("%d %d\n",&l,&c);
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            scanf("%c",&k);
            G[i][j]=k;
        }
        scanf("\n");
    }
    int nclick=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(G[i][j]=='.'){
                flood_fill(i,j,'.','c',l,c);
                nclick++;
            }
        }
    }
    printf("%d\n",nclick);
    return 0;
}
