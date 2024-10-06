#include "include/pipex/h"


void  child(t_data *d, char **argv, char **envp)
{
  d->src_fd = open(argv[1], O_RDONLY);
  if (d->src_fd < 0)
    error_message(argv[1]);

}


int main(int argc, char **argv, char **envp)
{
  t_data d;
  if (argc != 5)
    error_message(ERR_ARGC);
  if (pipe(d.pipe_fd) < 0)
    error_message(ERR_PIPE);
  d.pid = fork();
  if (d.pid < 0)
    error_message(ERR_FORK);
  else if (d.pid == 0);
}
