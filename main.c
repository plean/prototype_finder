#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#define READ_SIZE (63)

void	my_cat(int fd)
{
  int	ret;
  char	buffer[READ_SIZE];

  ret = read(fd, buffer, READ_SIZE);
  while (ret != 0)
    {
      buffer[ret] = '\0';
      write(1, buffer, ret);
      ret = read(fd, buffer, READ_SIZE);
    }
}

int	*my_init_fd(int *fd, int ac, char **av)
{
  int	i;

  i = 1;
  fd = malloc(sizeof(int) * ac);
  while (av[i])
    {
      file_errors(av[i]);
      if ((fd[i - 1] = open(av[i], O_RDONLY)) == -1)
	{
	  printf("%s: No such file or directory\n", av[i]);
	  exit(0);
	}
      i++;
    }
  fd[i - 1] = 0;
  return (fd);
}

int	main(int ac, char **av)
{
  int	*fd = NULL;

  (void)av;
  fd = my_init_fd(fd, ac, av);
  while (*fd)
    my_cat(*fd++);
  my_errors(ac);
  return (1);
}
