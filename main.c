#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "maker.h"

void	print_protoss(int fd)
{
  int	z = 0;
  char	*buffer;
  while ((buffer = get_next_line(fd)))
    {
      z = is_printable(buffer, z);
      free(buffer);
    }
}

int	main(int ac, char **av)
{
  int	*fd = NULL;

  my_errors(ac);
  fd = my_init_fd(fd, ac, av);
  while (*fd)
    print_protoss(*fd++);
  printf("\n");
  return (1);
}
