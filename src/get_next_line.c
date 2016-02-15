#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/*
** get_next_line is a function that return the next line (no shit sherlock)
** of the given file descriptor.
** It was not made by me but by one of my friend Bailly Jamy
*/

char	*gnl_strcpy(char *src, char c, int len_line)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(sizeof(char *) * (len_line + 1))) == NULL)
    return (NULL);
  while (i != len_line)
    {
      dest[i] = src[i];
      i++;
    }
  dest[len_line] = c;
  if (len_line != 0)
    free(src);
  return (dest);
}

int	gnl_read(char *buffer, const int fd, int *i)
{
  int	len_read;

  if ((len_read = read(fd, buffer, READ_SIZE)) < 0)
    return (-1);
  *i = 0;
  return (len_read);
}

char	*return_null_or_zero(char *line, int i, int len_read, int len_line)
{
  if (i - 1 == len_read && len_read != READ_SIZE && !line[i - 1])
    return (NULL);
  else
    return (gnl_strcpy(line, '\0', len_line));
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE];
  char		*line;
  int		len_line;
  static int	len_read;
  static int	i;

  len_line = 0;
  line = "";
  if (i == 0)
    len_read = ((len_read = gnl_read(buffer, fd, &i)) <= 0) ? 0 : len_read;
  while (len_read != 0)
    {
      if (i == len_read)
	len_read = ((len_read = gnl_read(buffer, fd, &i)) <= 0) ? 0 : len_read;
      if (buffer[i] == '\n' || (i == len_read && len_read != READ_SIZE))
	{
	  i++;
	  return (line = return_null_or_zero(line, i, len_read, len_line));
	}
      if ((line = gnl_strcpy(line, buffer[i], len_line)) == NULL)
	return (NULL);
      i++;
      len_line++;
    }
  return (NULL);
}
