NAME =  philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pthread

INC = -I ./includes/

SRCS = srcs/main.c \

OBJS = $(SRCS:.c=.o)

#Rules
#.c.o:
#		$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):
			@$(CC) $(CFLAGS) $(INC) $(SRCS) -o $(NAME)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

norm:
		norminette $(INC) $(SRCS)

.PHONY: all clean fclean re
			
