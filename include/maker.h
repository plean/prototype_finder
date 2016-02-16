#ifndef MAKER_H_
# define MAKER_H_

# include <stdio.h>

void	check_file(const char *str);
void	my_show_error();
void	my_show_version();
int	open_files(FILE **file, int file_count, char **file_names);
int	is_printable(const char *str, int z);

#endif /* !MAKER_H_ */
