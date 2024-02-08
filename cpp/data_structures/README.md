# Data Structures

## LowerUperBound & Sort

```cpp
// log(n)
// Lower : iterador para o primeiro elemento que é maior ou igual ao valor passado.
// Upper: iterador para o primeiro elemento que é maior que o valor passado.
// Binary search : retorna um bool , se ta la ou não.

auto lower = lower_bound(data.begin(), data.end(), 4);
binary_search(data.begin(), data.end(), 3); // true

// sort - > n log n | stable_sort() - > n log^2 n
stable_sort(arr.begin(), arr.end(), greater<int>()); 

```

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
