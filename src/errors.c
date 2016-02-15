#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "maker.h"

void	file_errors(char *str)
{
  int	test;

  test = open(str, O_DIRECTORY); /* Check if the string matches to a directory. */
  if (test != -1)
    {
      printf("%s: Is a directory\n", str);
      close(test);
      exit(0);
    }
  close(test);
  test = open(str, O_RDONLY);
  if (errno == EACCES || errno == ENOENT)
    {
      printf("%s: No such file or directory\n", str); /* Check if the string exist. */
      close(test);
      exit(0);
    }
  close(test);
}


void	my_errors(int ac)
{
  if (ac == 1)
    {
      my_show_error();
      exit (0);
    }
}
