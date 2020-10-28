#include"headers.h"
#define lli long long int

void pinfo(lli ink,char* ch[])
{
	pid_t pid;
	
		char arr[10000],arr2[1000000],arr3[100000];
		char stat;
		lli memory;
		int f1,f2;
		FILE *fd;
		//pid_t pid;
		char s[]="State";
		char v[]="VmSize";
		//if(flagk==0)
		//{
			if(ink!=1)
				pid = atoi(ch[1]);
			else if(ink==1)
				pid = getpid();    //getting process id
		//}
		sprintf(arr,"/proc/%d/stat",pid);
		f1 = open(arr, O_RDONLY);
	    f2 = open(arr, O_RDONLY);
	    if(f1<0)
	    {
	    	perror("Error : No such process exists\n");
	    	printf(":'(");
	    }
	    else
	    {
	    	lli i,j,k,fl;
			fd=fopen(arr,"r");
			fscanf(fd, "%*d %*s %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lld %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d", &stat, &memory);
	        fclose(fd);
	        sprintf(arr,"/proc/%d/exe",pid); //path
	        int l = readlink(arr,arr2,sizeof(arr2));
	        arr2[l]='\0';
	        lli flag=-1;
			if(strcmp(dir,arr2)==0)
				strcpy(arr2, "~");
			else
			{
				for(i=0;dir[i];i++)
				{
					if(arr2[i]==dir[i])
						continue;
					if(arr2[i]!=dir[i])
					{
						flag = i;
						break;
					}
				}
				if(flag!=0 && flag!=-1)
					strcpy(arr3,arr2);
				if(flag==-1)
				{
					arr3[0]=126;
					for (k = 1, j = i; arr2[j]; k++, j++)
					{
						char aa;
						aa=arr2[j];
						arr3[k]=aa;
					}
					fl=k;
					arr3[fl]='\0';
				}
			}

			printf("pid -- %d\n", pid);
		    printf("Process Status -- %c\n", stat);
		    printf("memory -- %llid\n", memory);
		    printf("Executable Path---  %s\n", arr3);
		    printf(":')");
		}
	

}