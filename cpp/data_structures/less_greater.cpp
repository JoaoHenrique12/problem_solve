#include<bits/stdc++.h>

using namespace std;

void printi(vector<pair<int,int>> const& vt) 
{
  cout << "Values: ";

  for( auto i : vt)
    cout << "(" << i.first << ", " << i.second << ") ";

  cout << '\n';
}

// Less
bool second_first(pair<int,int> const& el1, pair<int,int> const& el2)
{
  if( el1.second == el2.second)
    return el1.first < el2.first;

  return el1.second < el2.second;
}

// Greater
bool second_first_inverse(pair<int,int> const& el1, pair<int,int> const& el2)
{
  if( el1.second == el2.second)
    return el1.first > el2.first;

  return el1.second > el2.second;
}

bool sparse_first_second(pair<int,int> const& el1, pair<int,int> const& el2)
{
  if( el1.first == el2.first)
    return el1.second > el2.second;

  return el1.first < el2.first;
}

int main()
{
  vector<pair<int,int>>idade_altura = { make_pair(18,166), make_pair(15,190), make_pair(15,180), make_pair(15,181), make_pair(13,190) };

  cout <<"Default.\n";
  printi(idade_altura);

  sort(idade_altura.begin(), idade_altura.end(), less<pair<int,int>>());

  cout <<"\nNormal sort.\n";
  printi(idade_altura);

  sort(idade_altura.begin(), idade_altura.end(), greater<pair<int,int>>());

  cout <<"\nInverse sort.\n";
  printi(idade_altura);

  sort(idade_altura.begin(), idade_altura.end(), second_first);

  cout <<"\nSecond_First sort.\n";
  printi(idade_altura);

  sort(idade_altura.begin(), idade_altura.end(), second_first_inverse);

  cout <<"\nSecond_First Inverse sort.\n";
  printi(idade_altura);

  sort(idade_altura.begin(), idade_altura.end(), sparse_first_second);

  cout <<"\nSparse first second.\n";
  printi(idade_altura);

  return 0;
}
