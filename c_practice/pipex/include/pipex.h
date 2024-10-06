#ifndef PIPEX.H
 #define PIPEX.H

/*--------------------Library--------------------*/

#include <sys/types.h>
#include <sys/wait.h>


/*--------------------Macro--------------------*/

#define ERR_ARGC "Invaild number of Arguments"
#define ERR_PIPE "Failed to open pipe"
#define ERR_FORK "Failed to forking"
#define ERR_CMD "Commond not found"


/*--------------------Struct--------------------*/

typedef struct s_data
{
  int pipe_fd[2];
  pid_t pid;
} t_data;

#endif
