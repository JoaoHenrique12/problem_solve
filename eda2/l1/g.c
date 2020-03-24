#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int max = 99999;
	char next_city[max][30];
	size_t ini = 0, fim = 0;
	char city[50];

	memset( next_city, '\0', sizeof next_city );
	
	short insert_rule = 0;
	char last_letter = '#';
	size_t auxil;
	short pos_last_letter;
	while( scanf("%s\n",city)!= EOF )
	{
		// verifica
		if( last_letter - 32 == city[0]  && !insert_rule)
		{
			auxil = (fim++)%max;
			strcpy(next_city[auxil],city);
			insert_rule = 1;
			continue;
		}
		// printa
		
		printf("%s\n",city);
		// pega ultima letra

		pos_last_letter = strlen(city) - 1;
		last_letter = city[pos_last_letter];
		insert_rule = 0;
	}

	for(ini = 0; ( fim ) % max != ini ; ini++)
	{
		strcpy(city,next_city[ini]);
		// verifica
		if( last_letter - 32 == city[0]  && !insert_rule)
		{
			auxil = (fim++)%max;
			strcpy(next_city[auxil],city);
			insert_rule = 1;
			continue;
		}
		// printa
		
		printf("%s\n",city);
		// pega ultima letra

		pos_last_letter = strlen(city) - 1;
		last_letter = city[pos_last_letter];
		insert_rule = 0;
	}
	return 0;
}
