#include "headers.h"
#define lli long long int
#define dup dup
#define dup2 dup2
#define cl close

int status;
int redirection_check(char reco[])
{
    char *token[100000];
    lli k = 0, r;
    token[0] = strtok(reco, "  \r\n");

    while (token[k] != NULL) //Separating tokens within the cmnd
    {
        k=k+1;
        token[k] = strtok(NULL, "   \r\n");
    }
    lli j=0;
    while(j<k)
    {
        for (lli i = 0; token[j][i]; i++)
            if ( (token[j][i] == '>' && token[j][i + 1] == '>') ||(token[j][i] == '>')  || token[j][i] == '<')
            {
                if( r == 0)
                {
                    if (token[j][i] == '>' )
                    {
                        if( token[j][i + 1] == '>')
                        {
                            i++;
                        }
                    }
                    r = 1;
                }
                else if ( r == 1)
                {

                    if (token[j][i] == '>' )
                    {
                        if( token[j][i + 1] == '>')
                        {
                            i++;
                        }
                    }
                    r = 2;
                }
            }
            j++;
    }
    lli flag;
    flag=r;
    return flag;
}
void choice(int fds[], char *fro[], int k, int oldin, int oldout)
{
    if (strncmp(fro[0], "pwd",3) == 0) //cmnd : PWD
        pwd(k,fro);
    else if (strncmp(fro[0], "cd",2) == 0) //cmnd : CD
    {
        cd(k,fro);
    }

    else if (strncmp(fro[0], "echo",4) == 0) //cmnd : ECHO
    {
        echo(k,token);
    }
    else if (strncmp(fro[0], "ls",2) == 0) // cmnd :LS
    {
        ls(k,fro);
    }
    else if (strncmp(fro[0], "pinfo",5) == 0) //cmnd :PINFO
        pinfo(k,fro);
    else if (strcmp(fro[0], "jobs") == 0)
        myjob(fro);
    else
    {
        int k = execvp(fro[0], fro);
        if(k>=0)
        { }
        else
        {
            perror("myshell:Error\n");
            printf(":'(");
            dup2(oldout, 1);
            cl(fds[0]);
        }
    }
}

void both(char com[], long long app)
{
    char  in_file[100000],  out_file[100000];
    strcpy(out_file, "");
    strcpy(in_file, "");
    int fds[10];
    lli i=0;
    while(i<10)
    {
        fds[i] = -1;
        i++;
    }
    char  delim[10];
    lli k = 0;
    char greater[1]=">";
    char great[2]=">>";
    if (app != 10)
        strcpy(delim, greater);
    else
        strcpy(delim, great);
    char *chk = strtok(com, delim);
    char *cmnd[100000];
    while (chk != NULL)
    {
        char *ccc=chk;
        chk = strtok(NULL, delim);
        cmnd[k++] = ccc;
     //   chk = strtok(NULL, delim);
    }
    char *tmp1[100000];
    if (k == 2)
    {
        tmp1[0]=strtok(cmnd[1],"    \n\r");   //OUTPUT FILE
        strcpy(out_file, tmp1[0]);
    }

    char *tmp2[100000];
    tmp2[0] = strtok(cmnd[0], "<");
    char *tmp3[100000];
    k = 0;
    while (tmp2[k] != NULL)
    {
        k++;
        tmp2[k] = strtok(NULL, "<");
    }
    if (k == 2)
    {
        tmp3[0] = strtok(tmp2[1], " \t\n\r");
        strcpy(in_file, tmp3[0]);
    }
    char *fro[10000];
    fro[0] = strtok(tmp2[0], "    \n\r");
    k = 0;
    while (fro[k] != NULL)
    {
        k=k+1;
        fro[k] = strtok(NULL, "    \n\r");
    }
    int outfill = strcmp(out_file,"");
    int infill = strcmp(in_file,"");


    if (outfill != 0 && infill == 0) //HAS OUTPUT REDIRECTION ONLY
    {
        int oldout = dup(STDOUT_FILENO);
        int pid = fork();
        int fdso = fds[0];
        if (app == 10)
            fds[0] = open(out_file, O_APPEND | O_WRONLY | O_CREAT, 0644);
        if (app != 10)
            fds[0] = open(out_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);

        dup2(fds[0], 1);

        int z=0;
        if (pid == z)
        {
            choice(fds,fro,k,-1,oldout);

            exit(0);
        }
        if(pid!=z)
        {
            while (wait(&status) != pid)
                ;

            dup2(oldout, 1);
            cl(fds[0]);
        }
    }

    else if (infill != 0 && outfill == 0) // HAS INPUT REDIRECTION ONLY
    {
        // printf("came into input\n");
        int oldin = dup(STDIN_FILENO);
        int pid = fork();
        fds[0] = open(in_file, O_RDONLY);
        int fdso = fds[0];
        if (fdso < 0)
        {
            perror("File doesn't exist\n");
            printf(":'(");
        }
        int z=0;
        if (pid == z)
        {
            if (fdso < 0)
                ;
            if(fdso>=0)
            {
                dup2(fdso, 0);
                choice(fds,fro,k,oldin,-1);
                dup2(oldin, 0);
            }
            exit(0);
        }
        if(pid != z)
            while (wait(&status) != pid)
                ;
    }

    else if((outfill != 0 && infill!=0) || (outfill==0 && infill==0))
    {
       ///INPUT AND OUTPUT
        int oldout = dup(STDOUT_FILENO);
        int oldin = dup(STDIN_FILENO);
        int pid = fork();
        if (app == 10)
            fds[1] = open(out_file, O_APPEND | O_WRONLY | O_CREAT, 0644);
        if (app == 5)
            fds[1] = open(out_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
        fds[0] = open(in_file, O_RDONLY);
         if (fds[0] < 0)
         {
            perror("file doesn't exist\n");
            printf(":'(");
        }

        dup2(fds[1], 1);
        if (pid == 0)
        {
            int fdso = fds[0];
            if (fdso < 0)
                ;
            else if(fdso>=0)
            {
                dup2(fds[0], 0);
                choice(fds, fro, k, oldin, oldout);
                dup2(oldin, 0);
            }
            exit(0);
        }
        if(pid!=0)
        {
            while (wait(&status) != pid)
                ;

            dup2(oldout, 1);
            cl(fds[0]);
        }
    }
  //  printf(":')");
}

void redirection(char *token[], long long k, char list_com[], int redflag)
{
    lli app = 5, a = 0, i = 0;
    while(i<k)
    {
        if (strncmp(token[i], ">>",2) == 0)
        {
            app = 10;
            a += 1;
        }
        i++;
    }
    both(list_com, app);
}
