CC	= cc

RM     	= rm -f

CFLAGS 	+= -W -Wall -Wextra -pedantic -I./include

NAME  	= prototype_finder

SRCS   	= main.c \
	  src/errors.c \
	  src/help.c \
		src/init.c \
		src/is_printable.c

OBJS   	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:   clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
