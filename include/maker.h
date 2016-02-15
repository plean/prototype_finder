#ifndef MAKER_H_
# define MAKER_H_

# include "get_next_line.h"

void	file_errors(char *str);
void	my_errors(int ac);
void	my_show_error();
void	my_show_version();
int	*my_init_fd(int *fd, int ac, char **av);
int	is_printable(char *str, int z);
void	my_flags(char **av);

#endif /* !MAKER_H_ */
