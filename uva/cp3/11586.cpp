#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	while(n--)
	{
		string aux;
		getline(cin,aux,'\n');
		int loop = 0;
		for( size_t i = 0; i < aux.size() ; i++ )
		{
			if(aux[i] == 'M')
				loop++;
			else if(aux[i] == 'F')
				loop--;
		}
		if(loop == 0 && (aux.size() != 2))
			cout << "LOOP\n";
		else
			cout << "NO LOOP\n";
	}

	return 0;
}
