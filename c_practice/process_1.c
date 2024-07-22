#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//このコードは、親プロセスが子プロセスを作成し、その子プロセスで指定されたコマンドを実行するという内容です

int main(int argc, char *argv[])
{
	pid_t pid;
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <command> <arg>\n", argv[0]);
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		fprintf(stderr, "fork(2) failed\n");
	}
	if (pid == 0)//子プロセスの場合
	{
		execl(argv[1], argv[1], argv[2], NULL);
		perror(argv[1]);
		exit(99);
	}
	else //親プロセスの場合
	{
		int status;
		waitpid(pid, &status, 0);
		printf("child (PID=%d) finished;\n ", pid);
		printf("parents process PID%d\n", getpid());
		if (WIFEXITED(status))
			printf("exit, status=%d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("signal, sig=%d\n", WTERMSIG(status));
		else
			printf("abnormal exit\n");

		exit(0);
	}
}


/*

//pid_t とは　https://jp-seemore.com/iot/26767/

*/
