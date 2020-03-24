#include<stdio.h>
#include<string.h>

char text[1010][1010];
int lines,memory_col = 0;

void out_of_bound_corrector(int* l, int* c)
{
	if( *l < 0 ) *l = 0;
	if( *l >= lines) *l = lines-1;

	size_t max_col = strlen(text[*l]);
	
	if( *c < memory_col ) *c = memory_col;

	if( *c < 0){ memory_col = *c; *c = 0; }
	if ( *c >= max_col) { memory_col = *c; *c = max_col - 1; }

}

void down( int* l, int* c)
{
	*l = *l + 1;
	out_of_bound_corrector(l,c);
}

void up ( int* l, int* c)
{
	*l = *l - 1;
	out_of_bound_corrector(l,c);
}

int main()
{
	scanf("%d\n",&lines);

	memset(text,'\0',sizeof text);

	for(size_t i = 0; i < lines; i++)
		scanf("%[^\n]\n",text[i]);

	int l,c;
	scanf("%d %d\n",&l,&c);
	l--;c--;
	memory_col = c;
	
	char aux;
	while(scanf("%c\n",&aux)!=EOF)
	{
//		printf("________\tletra:%c\n\n",aux);
		if( aux == 'j' )
			down(&l,&c);
		else
			up(&l,&c);
		printf("%d %d %c\n",l+1,c+1,text[l][c]);

	}
	return 0;
}
