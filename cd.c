#include"headers.h"
#define llii long long int
//function for cd
void cd(llii ink,char *ch[])
{ 
    if(strncmp(ch[1],"-",1)!=0)
   	{
   		getcwd(arrcd,1000);
   	}
	llii i,flag;
	flag=0;
	for(i=0;ch[i]!=NULL;i++)
    {
        if(strncmp(ch[i],"&",1)==0)
        {
            if(ch[i+1]==NULL)
            {
                 printf("command: %s not found \n",ch[0] );
                 flag=1;
                break;
            }
        }
      
    }
    if(flag==0)
    {
		if(ink>2)
		{
			printf("Too many arguments given\n");
			printf(":'(");
		}
		else if(ink>1)
		{
			int len;
			if(strncmp(ch[1],"/",1)==0)
			{
				chdir(ch[1]);}
			else{
			char buff[1000];
			getcwd(buff,1000);
			strcat(buff,"/");
			strcat(buff,ch[1]);
			if(strncmp(ch[1],"-",1)==0)
			{
				chdir(arrcd);
				printf("%s\n",arrcd);
				printf(":')");
			}
			chdir(buff);
			
			}
			
		}
		else
		{
			chdir(dir);
		}
	}
}