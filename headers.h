#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include<time.h>
#include<grp.h>
#include <sys/wait.h>
#include<fcntl.h>
#include<errno.h>

void echo(long long int ink,char * ch[]);
void pwd(long long int ink,char *ch[]);
void ls(long long int ink,char *ch[]);
void cd(long long int ink,char *ch[]);
void pinfo(long long int ink,char * ch[]);
int pipecheck(char com[]);
void piping(char *commands[], long long k);
void redirection(char *token[], long long int k, char list_com[], int redflag);
int redirection_check(char ogcom[]);
void both(char com[], long long int app);
void choice(int fds[], char *from[], int k, int oldin, int oldout);
int set_env(char *ch[]);
int unset_env(char *ch[]);
long long int myjob(char *ch[]);
long long int killjobs(char *ch[]);
long long int overkills(char *ch[]);
long long int bgjob(char *ch[]);
long long int fgjob(char *ch[]);
//void pip(char * buffer);
//char ** split_pipe(char * buffer);
void quit();
void print();
void fun(char **input, int cnt);
long long int bp(char *input[]);
char dir[1024];
char cwd[200000];
struct hostent *host_entry; 
int hostname; 
char hostbuffer[256]; 
int star[1000004];
char *bg_arr[1000005];
int redflag;
char *token[100000];
char **input;
char arrcd[10000];