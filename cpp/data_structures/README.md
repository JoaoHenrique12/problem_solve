# Data Structures

## Less & Greater

```cpp
vector<pair<int,int>>idade_altura;
sort(idade_altura.begin(), idade_altura.end(), less<pair<int,int>>());
sort(idade_altura.begin(), idade_altura.end(), greater<pair<int,int>>());

bool less_by_second(pair<int,int> const& el1, pair<int,int> const& el2) {return false;}
sort(idade_altura.begin(), idade_altura.end(), less_by_second);
```

## Tuple

```cpp
tuple<string,int,int>posicaoVida("StringPadrao",2,3);
posicaoVida = make_tuple("Jc",2,3);
get<0>(posicaoVida) = "KKK";
```
