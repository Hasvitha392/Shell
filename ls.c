#include"headers.h"
#define lli long long int
#define pff printf
#define c char
#define ss struct
void ls(lli ink,char *ch[])
{
    
		lli flagl,flaga,i,j; 
	    c arr[1000];
	    getcwd(arr,sizeof(arr));
		for(i=1;i<ink;i++) 
		{ 
			if(ch[i][0]!='-')
				strcpy(arr,ch[i]);
	    	else if(ch[i][0]=='-') 
	        { 
	        	j=1;
	        	while(j<strlen(ch[i]))
	            {	 
	            	if(ch[i][j]=='a') 
	            		flaga=1;
	            	if(ch[i][j]=='l')
	            		flagl=1;
	            	j++;
	            } 
	        }     
	    }
	    ss dirent *dir_st;
	    c path[10000];
	    c buffer[1000],buffer1[1000],a[1000];
	    lli sizeofdirectory;
	    chdir(arr);
	    getcwd(buffer,sizeof(buffer)); 
	  	i=0;
	  	while(buffer[i]!='\0')
	  	{
	  		i++;
	  	}
	    sizeofdirectory=i;
	    DIR * direc=opendir(buffer);
	    getcwd(buffer1,sizeof(buffer1));
	    if(flagl==1 && flaga==0)
	    {    
	    	while((dir_st= readdir(direc))!=NULL) 
	    	{ 
	        	if(dir_st->d_name[0]!='.')              //condition for no flag a
	       		{ 
	        		ss stat st;
	        		ss passwd *user = getpwuid(st.st_uid);
	        		ss group  *group = getgrgid(st.st_gid);
	        		char slash[1000]="/";
	        		memset(path,0,1000);
	        		strcpy(path,buffer);
			        strcat(slash,dir_st->d_name);
			        strcat(path,slash);
			        stat(path,&st); 
			        c date[10];
			        strftime(date, 10, "%b %2d ", gmtime(&(st.st_mtime)));

			        // permisssions 
			        if(S_ISDIR(st.st_mode))
			        	pff( "d");
			        else
			        	pff ( "-");
			        if(st.st_mode & S_IRUSR) 
			        	pff("r" );
			        else
			        	pff ( "-");
			        if (st.st_mode & S_IWUSR) 
			        	pff( "w" );
			        else
			            pff ( "-");
			        if (st.st_mode & S_IXUSR) 
			        	pff( "x" );
			        else
			            pff ( "-");
			        if (st.st_mode & S_IRGRP) 
			        	pff( "r" );
			        else
			            pff ( "-");
			        if (st.st_mode & S_IWGRP) 
			        	pff("w" );
			        else
			            pff ( "-");
			        if (st.st_mode & S_IXGRP) 
			        	pff( "x" );
			        else
			            pff ( "-");
			        if (st.st_mode & S_IROTH) 
			        	pff("r" );
			        else
			            pff ( "-");
			        if(st.st_mode & S_IWOTH) 
			        	pff("w" );
			        else
			            pff ( "-");
			        if (st.st_mode & S_IXOTH) 
			        	pff("x" );
			        else
			            pff ( "-");
			     
			        pff(" ");
			        pff("%3lu",st.st_nlink);                        //hardlinks
			        pff(" ");
			        pff("%s",user->pw_name);                        //user
			        pff(" ");
			        pff("%s",group->gr_name);                       //groupname
			        pff(" ");
			        pff("%5lu",st.st_size);                        //size
			        pff(" ");
			        pff("%s",date);   
			        pff(" ");                                      //date
			        pff("%s",dir_st->d_name);                      //file name
			        pff("\n");
	       		} 
	     	}
	  	}
	  
	  
	  	if(flaga==1 && flagl==1)
	  	{
	   	 	while((dir_st= readdir(direc))!=NULL) 
	     	{ 
		        ss stat st;
		        ss passwd *user = getpwuid(st.st_uid);
		        ss group  *group = getgrgid(st.st_gid);
		        char slash[1000]="/";
		        memset(path,0,1000);
		        strcpy(path,buffer);
		        strcat(slash,dir_st->d_name);
		        strcat(path,slash);
		        stat(path,&st); 
		        c date[10];
		        strftime(date, 10, "%b %2d ", gmtime(&(st.st_mtime)));

		        //permisssions 
		        if(S_ISDIR(st.st_mode))
		        	pff( "d");
		        else
		        	pff ( "-");
		        if(st.st_mode & S_IRUSR) 
		        	pff("r" );
		        else
		        	pff ( "-");
		        if (st.st_mode & S_IWUSR) 
		        	pff( "w" );
		        else
		            pff ( "-");
		        if (st.st_mode & S_IXUSR) 
		        	pff( "x" );
		        else
		            pff ( "-");
		        if (st.st_mode & S_IRGRP) 
		        	pff( "r" );
		        else
		            pff ( "-");
		        if (st.st_mode & S_IWGRP) 
		        	pff("w" );
		        else
		            pff ( "-");
		        if (st.st_mode & S_IXGRP) 
		        	pff( "x" );
		        else
		            pff ( "-");
		        if (st.st_mode & S_IROTH) 
		        	pff("r" );
		        else
		            pff ( "-");
		        if(st.st_mode & S_IWOTH) 
		        	pff("w" );
		        else
		            pff ( "-");
		        if (st.st_mode & S_IXOTH) 
		        	pff("x" );
		        else
		            pff ( "-");
		        pff(" ");
		        pff("%3lu",st.st_nlink);                        //hardlinks
		        pff(" ");
		        pff("%s",user->pw_name);                        //user
		        pff(" ");
		        pff("%s",group->gr_name);                       //groupname
		        pff(" ");
		        pff("%5lu",st.st_size);                         //size
		        pff(" ");
		        pff("%s",date);   
		        pff(" ");                                      //date
		        pff("%s",dir_st->d_name);                      //file name
		        pff("\n");
	     	} 
	  	}
	     
	   	else if(flaga==0 && flagl==0) 
	  	{
	   		while((dir_st= readdir(direc))!=NULL)
	      	{
	        	if(dir_st->d_name[0]!='.')
	        	{
	         	pff("%s",dir_st->d_name);
	         	pff("  ");
	        	}
	      	}
	      	pff("\n");   
	  	}
	  	else if(flaga==1 && flagl==0)
	  	{
	  		while(( dir_st=readdir(direc))!=NULL)
	      	{ 
	      		pff("%s",dir_st->d_name); 
	      		pff("  ");
	      	}
	     	pff("\n");
	  	}
	 	printf(":')");
	 	chdir(buffer1);
	  	flaga=0;
	  	flagl=0;
  	
}
