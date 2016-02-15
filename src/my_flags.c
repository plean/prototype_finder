#include <stdlib.h>
#include <string.h>
#include "maker.h"

void	my_flags(char **av)
{
  int	i;

  i = 0;
  while (av[++i])
    {
      if (!(strcmp(av[i], "-h")) || !(strcmp(av[i], "--help")))
	{
	  my_show_error();
	  exit(0);
	}
      if (!(strcmp(av[i], "-v")) || !(strcmp(av[i], "--version")))
	{
	  my_show_version();
	  exit(0);
	}
    }
}
