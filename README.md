BRIEF OVERVIEW OF THE SHELL:
	This shell is a complete linux shell which supports most linux shell functionalities.
	The commands that are supported are:
	I. pwd : Prints the current working directory
	II. echo : prints a message on the terminal
		echo <"Hello">
	III. cd : changes the current working directory 
		cd
		cd ..
		cd ~
		cd <directory>
	IV. ls : lists the contents of a particular directory based on the flags given
		ls
		ls -a
		ls -l
		ls -al
		ls -la
	V. pinfo: gives the details of a particular process
	VI. quit: exits from the shell
	VII. Foreground Process : Processes that require the terminal to halt until their completion
	VIII. Background Process : Processes that run simultaneoulsy without interrupting the terminal.
	IX. Redirection:
		Both input and output redirections are supported.
		cat < file1.txt > file2.txt
	X.  Piping:
		Pipes two or more commands together
		more file.txt | wc
	XI. Piping with redirection:
		sort < sort.txt | grep a | wc > linex.txt
	XII.setenv :
		setting new environment variables
		setenv a 10
	XIII.unsetenv :
		unsetting environment variable
		unsetenv a
	XIV. jobs :
		 prints all the background jobs
		 jobs
	XV. kjob : 
		sends a signal to a particular job number
		kjob 1 9
	XVI. overkill :
		kills all background processes at once
		overkill
	XVII. fg :
		 brings a running or a stopped background job with given job number to foreground.
		 fg 1
	XVIII. bg:
		changes a stopped background job to a running background job.
		bg 1
	XIX. The terminal also supports 
		CTRL + Z
		CTRL + C

CODE FILES:
1. main.c :
	fun() : checks for any inbulit commands and calls the corresponding function fo that inbuilt command
	allot() : scans the input and divide into commands separated by spaces and newline and call the jobs functions, piping function, redirection function or fun function according to the inputs.
	print(): prints the username and the hostname of the shell
	checkHostname(),checkHostEntry() : to get the details of the hostname.
	ctrlZ() : handing the ctrlZ signal
	ctrlC() : handling the ctrlC signal

2. cd.c
	cd() : the current working directory will be changed to the argument provided

3. ls.c
	ls() : prints the list of files and directories based on the flags provided (-l,-a,-la)
4. echo.c
	echo() : Prints a string argument on the terminal
5. pwd.c
	pwd() : prints the present working directory
6. pinfo.c
	pinfo() : provides details about currently active/running processes. A particular process ID can also be given as an argument to obtain its details.
7. bp.c
	bg() : checks if the process is background or foreground and handles accordingly.


All the files are to be compiled as gcc "file name" ..  "file name"(all file names) -o outputfile.