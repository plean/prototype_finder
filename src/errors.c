#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "maker.h"

void	check_file(const char *str)
{
  int	test;

  test = open(str, O_DIRECTORY); /* Check if the string matches to a directory. */
  if (test != -1)
    {
      printf("%s: Is a directory\n", str);
      close(test);
      exit(1);
    }
  close(test);
  test = open(str, O_RDONLY);
  if (errno == EACCES || errno == ENOENT)
    {
      printf("%s: No such file or directory\n", str); /* Check if the string exist. */
      close(test);
      exit(1);
    }
  close(test);
}
