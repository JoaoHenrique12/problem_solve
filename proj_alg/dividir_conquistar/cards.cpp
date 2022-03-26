#include<bits/stdc++.h>
using namespace std;

bool compara(char a,char b){ return a == b; }

bool merge(string&arr, int l, int r,int mid,bool ans_left,bool ans_right)
{
  bool my_group_ans = false;
  int n1 = mid - l + 1, n2 = r - mid;
  int L[n1],R[n2];

  for( int i = 0 ; i < n1; i++)
    L[i] = arr[l + i];

  for( int i = 0 ; i < n2; i++)
    R[i] = arr[mid + i + 1];

  int i = 0,j = 0, k = l;
  while( i < n1 && j < n2 && (ans_left||ans_right) )
  {
    if( compara(L[i],R[j]) )
    {
      arr[k++] = R[j++];
      my_group_ans = true;
    }
    else
    {
      arr[k++] = L[i++];
    }
  }

  while( j < n2 )
    arr[k++] = R[j++];
  while( i < n1 )
    arr[k++] = L[i++];

  return my_group_ans;
}

bool c_cards(string&arr, int l, int r)
{
  if( l == r ) return true;

  int mid = l + (r - l)/2;

  bool ans_left = c_cards(arr, l, mid);
  bool ans_right = c_cards(arr, mid+1, r);

  bool my_group_ans = merge( arr, l, r, mid,ans_left,ans_right);

  if( ans_left && !my_group_ans )
  {
    bool second_ans = true;
    for(int i = l+1; i <= mid; i++)
      if(!compara(arr[l],arr[i]))
        second_ans = false;

    my_group_ans = my_group_ans|second_ans;
  }


  return my_group_ans;
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string st;
    cin >> st;
    bool g = c_cards(st,0,st.size()-1);
    if(g)
      cout << "More than a half is same card\t" << st << "\n";
    else
      cout << "Less than a half is same card\t" << st << "\n";
  }

  return 0;
}
