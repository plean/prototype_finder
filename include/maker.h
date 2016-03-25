#ifndef MAKER_H_
# define MAKER_H_

# include <stdio.h>

void	check_file(const char *str);
void	my_show_error(void);
void	my_show_version(void);
int	open_files(FILE **file, int file_count, const char **file_names);
int	is_printable(const char *str, int z);

#endif /* !MAKER_H_ */
