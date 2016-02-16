#include <stdio.h>
#include <string.h>

static int	is_struct_or_static(const char *str) /* Test if it's a structure or a static. */
{
  return (strncmp(str, "struct ", 6) && strncmp(str, "static ", 6));
}

static int	is_comment(const char *str) /* Test if it's a comment. */
{
  return (!((str[0] == '/' && str[1] == '*') ||
	  (str[0] == '*' && str[1] == '*') ||
	  (str[0] == '*' && str[1] == '/') ||
	  (str[0] == '/' && str[1] == '/') ||
	  (str[0] == '#')));
}

int	is_printable(const char *str, int z)
{
  int	i;
  int	k = 0;

  if (str[0] == 0)
    return (z);
  if (!(is_comment(str) && is_struct_or_static(str)))
    k = 1;
  i = -1;
  while (str[++i])
    {
      if (str[i] == '{') /* Basic parsing that increment if it find a '{' */
	z++;
      if (z == 0 && k == 0 && str[i] != ';' && str[i] != '\n')
	{
	  printf("%c", str[i]);
	  if (str[i] == ')' && k == 0) /* Check if it's the end of a prototype. */
	    {
	      printf(";\n");
	      k = 1;
	    }
	}
      if (str[i] == '}') /* and decrement if it find a '}' */
	z--;
    }
  if (z == 0 && str[0] != '}' && k == 0 && str[0] != '\n') /* Only do that if the prototype is on multiple lines. */
    printf("\n");
  /*
  ** The returned value is the number of '{' minus the number of '}' encountered.
  ** This value should always be positive.
  */
  return (z);
}
