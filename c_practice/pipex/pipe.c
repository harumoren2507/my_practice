#include <unistd.h>
#include <stdlib.h>

int	main() 
{
	int pipe_fd[2];
	pid_t pid;
	char write_nsg[] = "Hello, from parent";
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

	}
}

