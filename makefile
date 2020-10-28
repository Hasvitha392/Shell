CC=gcc

all:
		$(CC) -w -o shell -g alljobs.c echo.c ls.c piping.c redirection.c bp.c exit.c main.c pwd.c cd.c pinfo.c