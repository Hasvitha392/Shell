
#include"headers.h"
#define lli long long int
long long int bp(char *input[])
{
    lli bg=5;
    int st;
    lli i=0;
    for(i=0;input[i]!=NULL;i++)
    {
        if(strncmp(input[i],"&",1)==0)
        {
            if(input[i+1]==NULL)
            {
                bg=10;
                input[i]=NULL;
                break;
            }
        }
      
    }

    pid_t pid=fork();
   //  printf("%d\n",pid);
    if (pid < 0)
    {
        perror("ERROR:");
        return 1;
    }
    else if(pid==0)
    {
        if(bg==10&&strncmp(input[0],"vi",2)==0)
        {
              //  printf("YES");

            exit(EXIT_SUCCESS);
        }
        if ( execvp(input[0], input) < 0)
        {
            fprintf(stderr,"command: %s not found\n:'(",input[0] );
            //printf(":'(");
            exit(EXIT_FAILURE);
        }
       return 0;
    }
   
    if(bg==5)
    {
         bg_arr[pid]=input[0];
        pid_t wpid = waitpid (pid, &st, WUNTRACED);
    }
    if(bg==10)
    {
        
        bg_arr[pid]=input[0];
        if(pid!=0){printf("[%d]   %s\n",pid,bg_arr[pid]);}
        if(strncmp(input[0],"vi",2)==0)   star[pid]=2;
        else star[pid]=1;
        bg_arr[pid]=input[0]; 
       for (long long  i=0; i>=0 ;i++)
        { 
            int sta;
            
            if(input[i]==NULL)
            {
                break;
            }
            pid_t wpid = waitpid (-1, &sta, WNOHANG);
                    if(wpid>0)
                    {
                        if(WIFEXITED(sta)>0)
                        {
                           // status[wpid]=0;
                            fprintf(stderr,"%s with pid %d exited normally\n",bg_arr[wpid],wpid);
                            star[wpid]=0;
                            bg_arr[wpid]=NULL;
                        }
                         else if(WIFSIGNALED(sta))
                        {
                            fprintf(stderr,"%s with pid %d exited abnormally\n",bg_arr[wpid],wpid);
                        }
                    }  
                    
        } 
        return 1;
    }
    bg=5;
    return 1;
 
}
