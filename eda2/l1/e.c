#include<stdio.h>

int main()
{
	int fake_pilha[10010],pont = 0;
	
	int v[1001000];
	v[0] = 42;
	size_t i = 0;

	while( scanf("%d",&v[i++]), v[i-1] );

	int lim;
	scanf("%d",&lim);

	i--;
	int sum = 0;
	for( size_t j = 0; j < i; j++ )
	{
		sum += v[j];
		if( sum > lim )
		{
			sum = 0;
			fake_pilha[pont++] = v[j];
		}
	}
	while(pont--)
		printf("%d\n",fake_pilha[pont]);
	return 0;
}
