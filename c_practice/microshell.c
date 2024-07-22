#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int	main(int argc, char *argv[]) 
{
	int	i;
	int fd[2];
	int	tmp_fd;

	i = 0;
	tmp_fd = dup(STDIN_FILENO);//標準入力の複製を保存
	while (argv[i] != NULL && argv[i + 1] != NULL)
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{

		}
	}
}

//https://github.com/shackbei/microshell-42

/*
 



   このプログラムは、以下のような機能を持つ簡単なシェルです：
コマンドを実行します。
cd コマンドをサポートします。
コマンドをセミコロン (;) で区切って順次実行します。
パイプ (|) を使用して、コマンド間でデータをやり取りします。
*/	
