#include <stdio.h>

void	my_show_error(void)
{
  printf("Usage: ./prototype_finder [FILE [FILE]...]\n\n");
  printf("\t-h, --help\tDisplay this help and exit\n");
  printf("\t-v, --version\tDisplay program version information\n");
  printf("\n");
}

void	my_show_version(void)
{
  printf("prototype_finder 1.0\n");
  printf("\n");
  printf("Written by Jean Plancher.\n");
}
