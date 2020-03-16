#include<bits/stdc++.h>
using namespace std;

int main()
{
	double H, U, D , F;
	// H tamanho do poco
	// U subida diaria
	// D queda noturna
	// F cansaso.
	while(scanf("%d %d %d %d\n",&H, &U, &D, &F), H != 0 )
	{
		double ini_sub = 0.0, dis_sub = U, dis_tot = DS,dis_desc = U - D;
		double cansasso = F/100.0 * U;
		int day = 1;
		bool ok = false;
		if( dis_tot > H )
		{
			cout << "success on day 1 \n";
			continue;
		}
		while(!ok)
		{
			day++;
			ini_sub += dis_tot;
			

		}


	}
	return 0;
}
