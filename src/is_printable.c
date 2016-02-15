#include <stdio.h>
#include <string.h>

int	is_struct(char *str) /* Test if it's the beginning of a structure */
{
  if (!(strncmp(str, "struct ", 6)))
    return (0);
  return (1);
}

int	test_co(char *str) /* Test if it's a comment. */
{
  return ((str[0] == '/' && str[1] == '*') ||
	  (str[0] == '*' && str[1] == '*') ||
	  (str[0] == '*' && str[1] == '/') ||
	  (str[0] == '/' && str[1] == '/') ||
	  (str[0] == '#')) ? (0) : (1);
}

int	is_printable(char *str, int z)
{
  int	i;
  int	k = 0;

  if (str[0] == 0)
    return (z);
  if (!(test_co(str) && is_struct(str)))
    k = 1;
  i = -1;
  while (str[++i])
    {
      if (str[i] == '{') /* Basic parsing that increment if it find a '{' */
	z++;
      if (z == 0 && k == 0 && str[i] != ';')
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
  if (z == 0 && str[0] != '}' && k == 0) /* Only do that if the prototype is on multiple lines. */
    printf("\n");
  /*
  ** The returned value is the number of '{' minus the number of '}' encountered.
  ** This value should always be positive.
  */
  return (z);
}
