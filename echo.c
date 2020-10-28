#include"headers.h"
//function for echo
void echo(long long int ink,char *ch[])
{
	long long int i;
	for(i=1;i<ink-1;i++)
	{
		printf("%s ",ch[i]);

	}
	//printf("\n");
	printf("%s",ch[ink-1]);
	printf(":')");
}