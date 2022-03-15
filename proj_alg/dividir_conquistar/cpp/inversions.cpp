#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&arr, int l, int r,int mid)
{
  int inv = 0;
  int n1 = mid - l + 1, n2 = r - mid;
  int L[n1],R[n2];

  for( int i = 0 ; i < n1; i++)
    L[i] = arr[l + i];

  for( int i = 0 ; i < n2; i++)
    R[i] = arr[mid + i + 1];

  int i = 0,j = 0, k = l;
  while( i < n1 && j < n2 )
  {
    if( L[i] <= R[j] )
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
      inv += n1 - i ;
    }
  }

  while( i < n1 )
    arr[k++] = L[i++];
  while( j < n2 )
    arr[k++] = R[j++];

  return inv;
}

int inversions(vector<int>&arr, int l, int r)
{
  if( l == r ) return 0;

  int inv = 0;
  int mid = l + (r - l)/2;

  inv += inversions(arr, l, mid);
  inv += inversions(arr, mid+1, r);

  inv += merge( arr, l, r, mid);

  return inv;
}

int main()
{
  vector<int>arr = {1, 5, 4, 8, 10, 2, 6, 9, 12, 11, 3, 7} ;//
  int inv = inversions(arr,0,arr.size() - 1);
  for( int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << '\n';
  cout << inv << endl;

  return 0;
}
