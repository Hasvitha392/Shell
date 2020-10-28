#include"headers.h"
#define ll long long int
 
void pwd(ll ink,char* ch[])
{
    
	char buff[FILENAME_MAX];
    getcwd( buff, FILENAME_MAX );
    printf("%s\n", buff);
}