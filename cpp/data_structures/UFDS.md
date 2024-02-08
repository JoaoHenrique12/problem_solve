# UFDS

## Code

```cpp
class UFDS {
public:
    vector<int> parents, rank;

    UFDS(int N) {
        rank.assign(N, 0);
        parents.assign(N, 0);
        for(int i = 0; i < N; ++i) parents[i] = i;
    }

    int findSet(int i) {
        if (parents[i] == i) return i;
        return parents[i] = findSet(parents[i]);
    }

  void unionSet(int i, int j) {

    int x = findSet(i), y = findSet(j);

    if(x == y) return;

    if (rank[x] > rank[y]) 
      parents[y] = x;
    else {
      parents[x] = y;
      if (rank[x] == rank[y]) 
        rank[y]++;
    }
  }
};
```
