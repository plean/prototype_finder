#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "maker.h"

void	print_protoss(int fd)
{
  int	z;
  char	*buffer;

  z = 0;
  while ((buffer = get_next_line(fd)))
    {
      z = is_printable(buffer, z);
      free(buffer);
    }
}

int	main(int ac, char **av)
{
  int	*fd = NULL;

  my_errors(ac); /* Check if the number of parameters is exact. */
  my_flags(av); /* Check if some basic flags are used. */

  fd = my_init_fd(fd, ac, av);
  /* This function return a tab of fd (file descriptor). */

  while (*fd)
    print_protoss(*fd++);

  return (1);
}
