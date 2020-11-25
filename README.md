## BRIEF OVERVIEW OF THE SHELL:
This shell is a complete linux shell which supports most linux shell functionalities.
The commands that are supported are:
	
### pwd : 
Prints the current working directory
### echo : 
prints a message on the terminal
``` bash	
echo <"Hello">
```

### cd : 
changes the current working directory 
```bash
cd
cd ..
cd ~
cd <directory>
```

### ls : 
lists the contents of a particular directory based on the flags given
```bash
ls
ls -a
ls -l
ls -al
ls -la
```

### pinfo: 
gives the details of a particular process
### quit: 
exits from the shell
### Foreground Process : 
Processes that require the terminal to halt until their completion
### Background Process : 
Processes that run simultaneoulsy without interrupting the terminal.
### Redirection: 
Both input and output redirections are supported.
```bash
cat < file1.txt > file2.txt
```

### Piping: 
Pipes two or more commands together
```bash
more file.txt | wc
```

### Piping with redirection:
```bash
sort < sort.txt | grep a | wc > linex.txt
```

### setenv : 
setting new environment variables
```bash
setenv a 10
```

### unsetenv :
 unsetting environment variable
```bash
unsetenv a
```

### jobs : 
prints all the background jobs
```bash
jobs
```

### kjob : 
sends a signal to a particular job number
```bash
kjob 1 9
```

### overkill :	
kills all background processes at once
```bash
overkill
```

### fg : 
brings a running or a stopped background job with given job number to foreground.		 
```bash
fg 1
```

### bg: 
changes a stopped background job to a running background job.
```bash
bg 1
```

### The terminal also supports 
```bash
CTRL + Z
CTRL + C
```

## CODE FILES:
### main.c :
#### fun() : 
checks for any inbulit commands and calls the corresponding function fo that inbuilt command
#### allot() : 
scans the input and divide into commands separated by spaces and newline and call the jobs functions, piping function, redirection function or fun function according to the inputs.
#### print(): 
prints the username and the hostname of the shell
#### checkHostname(),checkHostEntry() :
 to get the details of the hostname.
#### ctrlZ() :
 handing the ctrlZ signal
#### ctrlC() : 
handling the ctrlC signal

### cd.c
#### cd() : 
the current working directory will be changed to the argument provided

### ls.c
#### ls() : 
prints the list of files and directories based on the flags provided (-l,-a,-la)

### echo.c
#### echo() : 
Prints a string argument on the terminal

### pwd.c
#### pwd() :
 prints the present working directory
### pinfo.c
#### pinfo() : 
provides details about currently active/running processes. A particular process ID can also be given as an argument to obtain its details.
### bp.c
#### bg() : 
checks if the process is background or foreground and handles accordingly.


All the files are to be compiled as gcc "file name" ..  "file name"(all file names) -o outputfile.
