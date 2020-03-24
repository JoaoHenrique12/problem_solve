#include<stdio.h>

int main()
{
	int stack[1010],sp;
	int vector[1010],vp;

	while( scanf("%d\n",&vp),vp)
	{
		for( size_t i = 0; i < vp; i++) scanf("%d",&vector[i]);

		short vai_da = 1;
		int nxt = 1;
		sp = 0;

		for( size_t i = 0; i < vp; i++)
		{
			if( vector[i] != nxt )
			{
				while( sp )
				{
					if( stack[sp - 1] == nxt )
					{
						sp--;
						nxt++;
					}
					else break;
				}
				if(sp == 0)
					stack[sp++] = vector[i];
				else if( stack[sp -1 ] > vector[i] )
					stack[sp++] = vector[i];
				else
					vai_da = 0;
			}
			else
				nxt++;

		}
		if( vai_da )
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
