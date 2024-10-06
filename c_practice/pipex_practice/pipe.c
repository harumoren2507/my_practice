#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main() {
	int pipefd[2];
	pid_t pid;
	char write_msg[] = "Hello, from parent";
	char read_msg[100];

	if (pipe(pipefd) == -1) {//ここでpipeは呼びだされている＆失敗のケースの条件文
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {//子プロセス
		close(pipefd[1]);
		read(pipefd[0], read_msg, sizeof(read_msg));
		printf("Child process received: %s\n", read_msg);
		close(pipefd[0]);
	}
	else {
		close(pipefd[0]);
		write(pipefd[1], write_msg, strlen(write_msg) + 1);
		close(pipefd[1]);
    wait(NULL);
	}

	return (0);
}

/*
 

プロセスのフォーク:

fork()で新しいプロセスを生成します。fork()が失敗した場合もエラーメッセージを表示して終了します。
子プロセス:

書き込み用のパイプを閉じて、pipefd[0]からメッセージを読み取ります。
読み取ったメッセージを表示し、読み取り用のパイプを閉じます。
親プロセス:

読み取り用のパイプを閉じて、write_msgをpipefd[1]に書き込みます。
書き込み用のパイプを閉じ、子プロセスの終了を待ちます。

*/
