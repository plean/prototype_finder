#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "maker.h"

static void	check_argument_count(int ac)
{
  if (ac == 1)
    {
      my_show_error();
      exit (1);
    }
}

static	void	print_prototype(const char *file_names)
{
  FILE		*file;
  char		*line = NULL;
  size_t	len = 0;
  ssize_t	read;
  int		z;

  z = 0;
  file = fopen(file_names, "r");
  if (file == NULL)
    exit(1);
  while ((read = getline(&line, &len, file)) != -1)
    z = is_printable(line, z);
  fclose(file);
  if (line)
    free(line);
}

static void	my_flags(int argc, const char **argv)
{
  int	i;

  for (i = 1; i < argc; i++)
    {
      if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
	{
	  my_show_error();
	  exit(1);
	}
      if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version"))
	{
	  my_show_version();
	  exit(1);
	}
    }
}

int	main(int argc, const char **argv)
{
  check_argument_count(argc); /* Check if the number of parameters is exact. */
  my_flags(argc, argv); /* Check if some basic flags are used. */

  printf("#ifndef TEST_H_\n");
  printf("# define TEST_H_\n\n");

  while (*++argv)
    print_prototype(*argv);

  printf("\n#endif /* !TEST_H_ */\n");

  return 0;
}
