#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int	main() 
{
	int pipe_fd[2];
	pid_t pid;
	char write_msg[] = "Hello, from parent";
	char read_msg[100];
	
	if (pipe(pipe_fd) == -1)
	{

	}	

	pid = fork();

	if (pid == -1)
	{
		//error処理　perrorとexitを使用
	}

	if (pid == 0)
	{
		close(pipe_fd[1]);
		read(pipe_fd[0], read_msg, sizeof(read_msg));
		printf("Child process received parent process %s\n", read_msg);
		close(pipe_fd[0]);
	}
	else
	{
		close(pipe_fd[0]);
		write(pipe_fd[1], write_msg, strlen(write_msg) + 1);
		close(pipe_fd[1]);
		wait(NULL);
	}
	return (0);
}

