#include <stdio.h>

void	my_show_error()
{
  printf("Usage: point_epee_maker [FILE [FILE]...]\n\n");
  printf("\t-h, --help\tDisplay this help and exit\n");
  printf("\t-v, --version\tDisplay program version information\n");
  printf("\n");
}

void	my_show_version()
{
  printf("point_epee_maker 0.8\n");
  printf("\n");
  printf("Written by Jean Plancher.\n");
}
