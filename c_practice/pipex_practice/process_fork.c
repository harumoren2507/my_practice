#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char *argv[]) {
	int id = fork();
	int n;

	if (id == 0)
	{
		printf("child return_value=0 %d\n", id);
		n = 1; 
	}
	else 
	{
		printf("parent return_value=child_processID %d\n", id);
		n = 6;
	}
	if (id != 0) {
		wait(NULL);//親プロセスが子プロセスの終了を待つ。
			   //子プロセスが終了すると、そのプロセスIDと終了ステータスなどの情報がシステムに保持されます。
			   //親プロセスが wait を呼び出すことで、システムリソースを解放する。
	}
	int	i;
	for (i = n; i < n + 5; i++) {
		if (i == 1)
			printf("child_process=");
		else if (i == 6)
			printf("parent_process=");
		printf("%d", i);
		if (i == 5)
			printf(" ");
		fflush(stdout);
	}
	if (id != 0) {
		printf("\n");
	}
	else
	{
		exit(0);
	}
	return (0);
}

