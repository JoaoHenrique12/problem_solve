# Data Structures

## Less & Greater

```cpp
vector<pair<int,int>>idade_altura;
bool less_by_second(pair<int,int> const& el1, pair<int,int> const& el2){ if( el1.second == el2.second) return el1.first < el2.first; return el1.second < el2.second; }
sort(idade_altura.begin(), idade_altura.end(), less_by_second);
```

## Tuple

```cpp
tuple<string,int,int>posicaoVida("StringPadrao",2,3);
posicaoVida = make_tuple("Jc",2,3);
get<0>(posicaoVida) = "KKK";
```

## Set

```cpp
.insert(element);
.erase(element); // Can erase iterator, value and [begin,end)

.count(element);
.find(element); // Get iterator.

.size(); .clear(); .empty();
```

## Map

```cpp
.clear();
.empty();
.size();
// Examples.
map<int, string> c = { {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"} };
    for (auto it = c.begin(); it != c.end();)
        if (it->first % 2 != 0) it = c.erase(it); else ++it;

if (mapa.find(“AMAZONAS”)!=mapa.end()) printf(“Encontrado…\n”)
```
