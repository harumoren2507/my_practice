



void  ft_send_bits(int pid, char *str)
{
  int i;
  int bit;

  i = 0;
  while (str[i])
  {
    bit = 7;
    while (bit >= 0)
    {
      if (str[i] & (1 << bit))
        kill(pid, SIGUSR2);
      else 
        kill(pid, SIGUSR1);
      usleep(200);
      bit--;
    }
    i++;
  }
}

int main(int argc, char *argv[])
{
  int pid;
  int i;

  i = 0;
  if (argc == 3)
  {
    pid = atoi(argv[1]);
    while (argv[2][i] != 0)
    {
      ft_send_bits(pid, argv[2][i]);
      i++;
    }
    ft_send_bits(pid, '\n');
  }
  else 
  {
    printf("error");
    return (1);
  }
  return (0);
}

