#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n_pess;
	bool first = true;
	while(scanf("%d\n",&n_pess) != EOF)
	{
		if( first ) 
			first = false;
		else
			cout << "\n";
	 	

		map<string,int>pers_money;
		vector<string>pers;
		string aux;

		while(n_pess--)
		{
			cin >> aux;
			pers.push_back(aux);
			pers_money[aux] = 0;
		}
		for( size_t i = 0; i < pers.size() ; i++)
		{
			int money,n_awarded;

			cin >> aux >> money >> n_awarded;
			
			if( n_awarded != 0)
				pers_money[aux] += -money + money%n_awarded;
			
			for(int j = 0; j < n_awarded ; j++)
			{
				cin >> aux;
				pers_money[aux] += money/n_awarded;
			}
		}
		for(string names: pers)
			cout << names << " " << pers_money[names] << "\n";
	}

	return 0;
}
