#include "headers.h"
#define lli long long int
#define cl close
#define d2 dup2

//***************************************************************************************************************
/*int redirection_check(char reco[])
{
    char *token[100000];
    token[0] = strtok(reco, " \t\r\n");
    lli k = 0, r;

    while (token[k] != NULL) //Separating tokens within the command
    {
        k++;
        token[k] = strtok(NULL, " \t\r\n");
    }
    for (lli j = 0; j < k; j++)
    {
        for (lli i = 0; token[j][i]; i++)
            if ((token[j][i] == '>') || token[j][i] == '<' || (token[j][i] == '>' && token[j][i + 1] == '>') && r == 0)
            {
                r = 1;
                if (token[j][i] == '>' && token[j][i + 1] == '>')
                    i++;
            }
            else if ((token[j][i] == '>') || token[j][i] == '<' || (token[j][i] == '>' && token[j][i + 1] == '>') && r == 1)
            {
                r = 2;
                if (token[j][i] == '>' && token[j][i + 1] == '>')
                    i++;
            }
    }
    return r;
}
*/
//**********************************************************************************************************
void piping(char *commands[], long long k)
{
    int pipingflag;
    int pip1[2], pip2[2], inp = 0, outp = 0;
    pid_t pid;
    char *part[10000], buffer[100000], reco[10000], temp[10000];
    pipingflag = 1;
    
    
    lli i=0;
    while(i<k)
    {
        char *part[10000], *part2[10000];
        strcpy(reco, commands[i]);
        strcpy(temp, commands[i]);
        int oldout, oldin, ofd, ifd, r = 0;
        r = redirection_check(temp);
        lli tw;
        tw = i%2;
        part[0] = strtok(reco, "   \n\r");
        long long ii = 0;
        while (part[ii] != NULL)
        {
            ii++;
            part[ii] = strtok(NULL, "   \r\n");
        }


        if(tw == 0)
        {
            int z = pipe(pip1);
            if (z < 0)
            {
                printf("Error: pipe could not be created\n");
                printf(":'(");
            }
        }
        if (tw == 1)
        {
            int z = pipe(pip2);
            if (z < 0)
            {
                printf("Error: pipe could not be created\n");
                printf(":'(");
            }
        }

        pid_t pid = fork();
        if(pid != 0)
        {
            wait(NULL);
            if (i == k - 1)
            {
                if (tw != 0)
                    cl(pip1[0]);
                else if(i%2 != 1)
                    cl(pip2[0]);

                if (outp == 1)
                {
                    d2(oldout, 1);
                    cl(ofd);
                }
            }
            else if (i == 0)
            {
                cl(pip1[1]);
                if (inp == 1)
                {
                    d2(oldin, 0);
                    cl(ifd);
                }
            }
           
            else if (tw != 0)
            {
                cl(pip1[0]);
                cl(pip2[1]);
            }
            if (tw == 0 && i!=0)
            {
                cl(pip2[0]);
                cl(pip1[1]);
            }
        }
        else if (pid == 0)
        {
            if (i == k - 1)
            {
                if(tw==0)
                {
                    d2(pip2[0], 0); //input from transit
                }
                if(tw==1)
                {
                    d2(pip1[0], 0); //Input from pipe
                }
                
            }
            else if (i == 0)
            {
                d2(pip1[1], 1); // output to pipe
                cl(pip1[0]);   //closing input end of pipe
                strcpy(temp, commands[i]);
            }
            
             else if (tw != 0)
            {
                d2(pip1[0], 0);  //input from pipe
                cl(pip1[1]);    // close output end of pipe
                d2(pip2[1], 1); // output to transit
            }


            else if (tw != 1)
            {
                d2(pip2[0], 0); //input from transit
                cl(pip1[0]);    // close input end of pipe
                d2(pip1[1], 1);  // output to pipe
            }

            if (r == 1)                       //redirection
            {
                redirection(part, ii, commands[i], r);
            }
            else if(r==2)
            {
                redirection(part, ii, commands[i], r);
            }

            else if(r!=1 && r!=2)
            {
                int z = execvp(part[0], part); // exec
                if (z < 0)
                {
                    printf("Error: command not found\n");
                    printf(":'(");
                }
                    
                if(r==0)
                    exit(0);
            }
            exit(0);
        }
        
        i++;
    }
    printf(":')");
}