#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "maker.h"

int	open_files(FILE **files, int file_count, const char **file_names)
{
  int	i;

  files = malloc(sizeof(FILE *) * file_count);
  if (files == NULL)
    return 1;
  for (i = 0; i < file_count; i++)
    {
      check_file(file_names[i]);
      files[i] = fopen(file_names[i], "r");
      if (files[i] == NULL)
	return 1;
    }
  return 0;
}
