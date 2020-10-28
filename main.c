#include "headers.h"
#define buffersize 50
#define ll long long int 
#define st size_t
#define spc 32                       //space
#define nline 10                    //newline
char *list_com[100000], *temp[100000];


void fun(char **input, int cnt)
{
    char *builtin_commands[] = {"cd","echo","pwd","ls","pinfo","quit"};
  	if (cnt == 0)
    	return;
    if(strncmp(input[0],"cd",2)==0)
    {
    	cd(cnt,input);
    	return;
    }
    if(strncmp(input[0],"echo",4)==0)
    {
    	echo(cnt,input);
    	return;
    }
    if(strncmp(input[0],"pwd",3)==0)
    {
    	pwd(cnt,input);
    	return;
    }
    if(strncmp(input[0],"ls",2)==0)
    {
    	//printf("YY\n");
    	ls(cnt,input);
    	return;
    }
    if(strncmp(input[0],"pinfo",5)==0)
    {
    	pinfo(cnt,input);
    	return;
    }
    if(strncmp(input[0],"quit",4)==0)
    {
    	quit();
    	return;
    }
    if(strncmp(input[0],"cd",2)!=0 && strncmp(input[0],"echo",4)!=0 && strncmp(input[0],"pwd",3)!=0 && strncmp(input[0],"ls",2)!=0 && strncmp(input[0],"pinfo",5)!=0 && strncmp(input[0],"quit",4)!=0 && strncmp(input[0],"jobs",4)!=0 && 
    	strncmp(input[0],"kjob",4)!=0 && strncmp(input[0],"setenv",6)!=0 && strncmp(input[0],"unsetenv",8)!=0 && strncmp(input[0],"overkill",8)!=0 && strncmp(input[0],"bg",2)!=0 && strncmp(input[0],"fg",2)!=0 )
    {
    	bp(input);
    }
    
}

void allot()
{
	char *buffer;
	st buffer_size = 500; 
	st foo;
	ll i, cnt, j, k, len;
	buffer = (char *)malloc(buffersize * sizeof(char));
	foo = getline(&buffer, &buffer_size, stdin);
	ll bufferlen=0;

	//printf("%lld\n",bufferlen);
	 int pipe,redirect,length;
	 pipe=0;redirect=0;length=0;
	
	if (buffer == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	if(buffer[0] == EOF)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
	for (i = 0; buffer[i] != nline; i++)
    {
    	if(buffer[i]=='|')
    	pipe=1;	
    	if(buffer[i]=='>' || buffer[i]=='<' || (buffer[i]=='>' && buffer[i+1]=='>')) {redirect=1;}
    }
    if(pipe==1 || redirect==1)
    {
    	char *command; 
    ssize_t size = 0;
    char ogcom[10000];
   list_com[0] = strtok(buffer, ";\n"); 
    long long t = 0;
    while (list_com[t] != NULL)
    {
      t++;
      list_com[t] = strtok(NULL, ";\n");
    }
	
    for (long long j = 0; j < t; j++)
    {
      strcpy(ogcom, list_com[j]);

      getcwd(cwd, sizeof(cwd));
      if (pipe) 
      {
        temp[0] = strtok(list_com[j], "|");
        long long k = 0;
        while (temp[k] != NULL)
        {
          k++;
          temp[k] = strtok(NULL, "|");
        }
        piping(temp, k);
        pipe=0;
      }
  		else
      {
        token[0] = strtok(list_com[j], " \t\r\n");
        long long k = 0;

        while (token[k] != NULL) //Separating tokens within the command
        {
          k++;
          token[k] = strtok(NULL, " \t\r\n");
        }
        
        for (long long j = 0; j < k; j++)
        {
          for (long long i = 0; token[j][i]; i++)
            if ((token[j][i] == '>') || token[j][i] == '<' || (token[j][i] == '>' && token[j][i + 1] == '>') && redflag == 0)
            {
              redflag = 1;
              if (token[j][i] == '>' && token[j][i + 1] == '>')
                i++;
            }
            else if ((token[j][i] == '>') || token[j][i] == '<' || (token[j][i] == '>' && token[j][i + 1] == '>') && redflag == 1)
            {
              redflag = 2;
              if (token[j][i] == '>' && token[j][i + 1] == '>')
                i++;
            }
        }
        if (redflag == 1 || redflag == 2) // FOR REDIRECTION
          redirection(token, k, ogcom, redflag);
      redflag=0;
      redirect=0;
    }
	}
    }
    else
    {
	    input = (char **)malloc(buffersize * sizeof(char *));
	    i=0;
	    while (i < buffersize)
	    {
	   		input[i] = (char *)malloc(1000 * sizeof(char));
	   		i++;
	    }
	    char sample[100];
	 	//printf("Y\n");
	  	len = i;
	    buffer[len]=';';
	    ll ilen,flen,m,cnn;
	    ilen=0;
	    m=0;
	    cnn=0;
	    cnt = -1;
	    for(i=0;i<=len;i++)
	    {
	    	if(buffer[i]==';')
	    	cnn++;
	    }

	    while(m<len+1)
	    {
	    	if(buffer[m]==';') 
	    	{ 
	    		flen=m; 
	    		cnt=-1;
	    		i=ilen;
	        	while(i<flen) 
	    		{

	       			k=0;
	            	for (j = i; buffer[j] != spc && j < flen; j++)
	       			{

	        			sample[k] = buffer[j];
	        			i++;
	        			k++;
	       			}

	       			if(k!=0)
	       				cnt=cnt+1;

	       			ll a;
	       			for (a = 0; a < k; a++)
	       			{
	         			input[cnt][a] = sample[a];
	       			}

	       			i++;
	    		}  
	    		int w;
	    		input[++cnt]=NULL;
          
	    		if(cnn==1){ if(strncmp(input[0],"echo",4)!=0){input[cnt-1][strlen(input[cnt-1])-1]='\0';}}
	   
	    		if(strncmp(input[0],"jobs",4)==0) {  myjob(input);}
	    		else if(strncmp(input[0],"kjob",4)==0) {  killjobs(input); }
	    		else if(strncmp(input[0],"setenv",6)==0) {  set_env(input); }
	    		else if(strncmp(input[0],"unsetenv",8)==0) {  unset_env(input); }
	    		else if(strncmp(input[0],"overkill",8)==0) {  overkills(input); }
	    		else if(strncmp(input[0],"bg",2)==0) {  bgjob(input); }
	    		else if(strncmp(input[0],"fg",2)==0) {  fgjob(input); }
	    		if(redirect==0) { fun(input,cnt);}
	    		
	    		ilen=flen+1;
	    	}
	    	m++;
	  	}
  
	}
	}
} 


void checkHostName(int hostname) 
{ 
    if (hostname == -1) 
    { 
        perror("gethostname"); 
        exit(1); 
    } 
} 
 
void checkHostEntry(struct hostent * hostentry) 
{ 
    if (hostentry == NULL) 
    { 
        perror("gethostbyname"); 
        exit(1); 
    } 
} 
char ini_dir[1000];
ll flag,a;
void print()
{
	ll b;
	hostname = gethostname(hostbuffer, sizeof(hostbuffer)); 
    	checkHostName(hostname); 
 		uid_t userid = geteuid();
    struct passwd *pw = getpwuid(userid);
    //username@hostname:~>
    printf("%s@", pw->pw_name);
    	host_entry = gethostbyname(hostbuffer); 
    	checkHostEntry(host_entry);
     	printf("%s:", hostbuffer);                   //username@hostname:~>
 		char curr_dir[1000];
    	getcwd(curr_dir, sizeof(curr_dir));        
    	getcwd(dir,sizeof(dir));                    //pinfo
    	b = strlen(curr_dir);
    	if(strncmp(ini_dir,curr_dir,a)==0 & a!=b)
    		printf("~%s>",&curr_dir[a]);
    	else if (strncmp(ini_dir, curr_dir, a) == 0 && a == b)  //checking if both are in the same directory
    		printf("~>"); 
    	else
    		printf("%s>", curr_dir);  
}
void ctrlZ(int sig)
{
    signal(SIGTSTP,ctrlZ);
}
void ctrlC(int sig)
{
    signal(SIGINT,ctrlC);
    fflush(stdout);
}



int main()
{
	signal(SIGTSTP,ctrlZ);
    signal(SIGINT,ctrlC);
    
  	flag = 0;
  	if (flag == 0)
  	{
    	getcwd(ini_dir, sizeof(ini_dir));
    	a = strlen(ini_dir);
    	flag = 1;
  	}
    /* Main Loop Starts */
  	while (1)
  	{
  		
  		print();
        allot();
    	

  	}
  	return 0;
}


