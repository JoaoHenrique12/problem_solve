#include<stdio.h>

int main()
{
	int soma = 0, num,aux;
	scanf("%d",&num);
	while(num--)
	{
		scanf("%d",&aux);
		soma += aux;
	}
	printf("%d\n",soma);
	return 0;
}
