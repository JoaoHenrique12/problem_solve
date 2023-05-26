# MATH

## ROUND
```cpp
double num = 3.8; 
int rounded_num = round(num);
cout << rounded_num << endl;
```

```python3
from math import ceil, floor

round(1.7)
round(1.3)
```

## Horner's Method

```cpp
int horner(int poly[], int n, int x)
{
    int result = poly[0]; // Initialize result
 
    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<n; i++)
        result = result*x + poly[i];
 
    return result;
}
```

## Sieve Eratostenes

```cpp
#define size_p 1000000

vector<bool>primes(size_p,true);
void sieve_eratosthenes()
{
  for( long long i = 2; i < (long long) sqrt(size_p) + 1; i++ )
  {
    long long j = i * i;
    while( j <= size_p )
      { primes[j] = false; j += i; }
  }
}
```

## Removing elements

### Removing specific number
```cpp
vector<int>numeros = {1,2,3,4,5};
numeros.erase(numeros.begin());
// Or
numeros.erase(numeros.find(3));
// Or
numeros.erase(numeros.begin(), numeros.begin() + 2);
```

### Removing bunch of same numbers

```cpp
vector<int>numeros = {1,2,3,4,5,2,2,2};
numeros.erase(remove(numeros.begin(),numeros.end(),2), numeros.end());
// Remove function returns an iterator and throw all elements found to
// the end of array.
```

## string::npos
```cpp
string a = "abcde";
if( a.find('K') != string::npos )
```

## stringstream

[material](https://www.geeksforgeeks.org/stringstream-c-applications/)

```cpp
stringstream stre(text);
```

## max\_element

```cpp
#include <algorithm>
int arr[] = {4, 2, 7, 1, 9};
int n = sizeof(arr) / sizeof(arr[0]);
int max_val = *std::max_element(arr, arr + n);
```
