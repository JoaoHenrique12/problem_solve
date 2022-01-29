# URI QUESTAO 1907
# Codigo tomando TLE, F. Vo volta pro cpp. A proposito ate esta data o problema so foi resolvido em c++ e c++17.
# IMPORTS
#from collections import deque
# VAR GLOBAL
global L,C,G
global dx, dy
dx = [0 , 0 ,-1 ,1] 
dy = [-1, 1 , 0 ,0]

# FUNCTIONS
def flood_fill(x,y,color,new_color):
    nxt_points = []
    nxt_points.append((x,y))
    while len(nxt_points) != 0:
        x,y = nxt_points.pop(0)
        if G[x][y] == color:
            G[x][y] = new_color

        for i in range(len(dx)):
            if ((x + dx[i]) >= L ) or ((x + dx[i]) < 0 ) or ((y + dy[i]) >= C ) or ((y + dy[i]) < 0 ):
                continue
            elif G[x + dx[i]][y + dy[i]] != color:
                continue
            else:
                nxt_points.append((x+dx[i],y+dy[i]))

    return 1

# MAIN
L,C = [int(k) for k in input().split()]
G = []
for i in range(L):
    G.append([c for c in input()])

nClick = 0
new_color = 'F'
color = '.'
for i in range(L):
    for j in range(C):
        if G[i][j] == color:
            nClick += flood_fill(i,j,color,new_color)

print(f"{nClick}")
