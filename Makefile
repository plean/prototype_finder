CC	= cc

RM     	= rm -f

CFLAGS 	+= -W -Wall -Wextra -pedantic -I./include

NAME  	= point_epee_maker

SRCS   	= main.c \
	  src/errors.c \
	  src/help.c

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
