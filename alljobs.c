#include"headers.h"
#define neg -1


int set_env(char *ch[])
{
	if(ch[1]==NULL)
	{
		printf("Inappropriate number of arguments");
		printf(":'(");
		return 0;
	}
	if(ch[2]==NULL)
	{
		ch[2]="";
	}
	else if(ch[2]!= NULL && ch[3]!=NULL)
	{
		printf("Inappropriate number of arguments");
		printf(":'(");
		return 0;
	}


	if(setenv(ch[1],ch[2],1)==neg)
	{
		printf("Setenv failed\n");
		printf(":'(");
	}
	return 1;
}



int unset_env(char *ch[])
{
	if(ch[1]==NULL)
	{
		printf("Inappropriate number of arguments");
		return 0;
	}
	if(unsetenv(ch[1])==-1)
	{
		printf("Setenv failed\n");
		printf(":'(");
	}
	return 1;

}



long long int myjob(char *ch[])
{
	long long int j;
	int i;
	i=0;j=0;
	char *str;
	int p;
	char r[300],s;
	for(i=0;i<100004;i++)
	{
		if(star[i]!=0)
		{


			if(bg_arr[i]!=NULL)
			{
				char *var=(malloc(sizeof(char)*1005));
				printf("%d\n",i);
				sprintf(var,"/proc/%d/stat",i);
				FILE *f=fopen(var,"r");
				if(f==NULL)
				{
					printf("File cannot be opened\n");
					printf(":'(");
					return 0;
				}
				long long int z=0;
				fscanf(f,"%d",&p);
				fscanf(f,"%s",r);
				fscanf(f,"%c",&s);
				if(s=='R') star[i]=2;
				if(s=='S') star[i]=1;
				if(s!='S' && s!='R') star[i]=1;
				if(star[i]==1)  str="stopped";
				else str="running";
				j++;
				//printf("[%lld]%s\t",j,str);
				//printf("%s[%d]\n",bg_arr[i],i);
				printf("[%lld]%s\t%s[%d]\n",j,str,bg_arr[i],i);
				//printf(":')");
			}
		}
	}
	printf(":')");
	return 1;
}


long long int killjobs(char *ch[])
{
	long long int j,i,pid;
	i=0;j=0;
	long long int a = atoi(ch[1]);
	long long int a1 = atoi(ch[2]);
	pid=0;
	i=0;
	while(i<1000004)
	{
		if(star[i]==0)
			{  }
		else
		{
			j++;
			if(a==j)
			{
				pid=i;
				//printf("%lld %lld\n",i,pid);
				break;
			}
		}
		i++;

	}


	kill(pid,a1);
	//printf("%lld\n",pid);
	if(a1==9)  star[pid],bg_arr[pid]= NULL;

}



long long int overkills(char *ch[])
{
	long long int i,j;
	i=0;j=0;
	while(i<100004)
	{
		if(star[i]!=0) j++,star[i]=0,bg_arr[i]=NULL,kill(i,9);
		i++;
	}
}



long long int bgjob(char *ch[])
{
	long long int i,j;
	i=0;j=1;
	long long int a=atoi(ch[1]);
	for(i=0;i<100004;i++)
	{
		if(star[i]!=0)
		{
			if(j==a)
			{
				kill(i,SIGCONT);
				star[i]=2;
				break;
			}
			else
			{
				j++;
			}
		}
	}
}




long long int fgjob(char *ch[])
{
	long long int i,j;
	i=0;j=1;
	long long int a=atoi(ch[1]);
	for(i=0;i<100004;i++)
	{
		if(star[i]!=0)
		{
			int s;
			if(j==a)
			{
				kill(i,SIGCONT);
                waitpid(i,&s,WUNTRACED);
                if(WIFEXITED(s)==1 || WIFSIGNALED(s)==1)
                {
                    bg_arr[i]=NULL;
                    star[i] =0;
                }
                break;	
			}
				j++;
		}
	}
}