#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "maker.h"

int	*my_init_fd(int *fd, int ac, char **av)
{
  int	i;

  i = 1;
  fd = malloc(sizeof(int) * ac);
  while (av[i])
    {
      file_errors(av[i]);
      fd[i - 1] = open(av[i], O_RDONLY);
      i++;
    }
  fd[i - 1] = 0;
  return (fd);
}
