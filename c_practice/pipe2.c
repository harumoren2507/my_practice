#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	fd[2];

	char buf[256]; //現在未使用
	pipe(fd);
	printf("\nfd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
	pipe(fd);
	printf("\nfd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
	close(fd[0]);
	close(fd[1]);
}

/*


 pipe()  creates  a  pipe,
		a  unidirectional data channel that can be used for interprocess communication.  The array
		pipefd is used to return two file descriptors referring to the ends of the pipe.  pipefd[0] refers to the read end of
		the  pipe.   pipefd[1] refers to the write end of the pipe.  Data written to the write end of the pipe is buffered by
		the kernel until it is read from the read end of the pipe.  For further details,
			see pipe(7).

		If flags is 0,
			then pipe2() is the same as pipe().  The following values can be bitwise ORed in flags to obtain  dif‐
		ferent behavior:


◆ファイルディスクリプタの割り当てについて:

UNIX系システムでは、プロセスが開くファイルごとに一意のファイルディスクリプタ番号が割り当てられます。通常、最初に割り当てられるファイルディスクリプタは0,
	1, 2で、標準入力、標準出力、標準エラー出力に予約されています。
次に利用可能なファイルディスクリプタは3から始まります。

int	main(void)
{
	int		fd[2];
	char	buf[256];

	pipe(fd);
	printf("\nfd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
	pipe(fd);
	printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
	close(fd[0]);
	close(fd[1]);
	pipe(fd);
	printf("\nafter close fd[0], fd[1]\n");
	printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
	close(fd[0]);
	pipe(fd);
	printf("\nafter close fd[0]\n");
	printf("fd[0] = %d, fd[1] = %d\n\n", fd[0], fd[1]);
	write(fd[1], "hello\n\0", 7);
	read(fd[0], buf, 255);
	printf("buf = %s", buf);
}

*/