NAME = philo

SRCS = argv_error.c main.c philo_cycle.c table.c time_and_status_manager.c utils.c

FLAGS = -Wall -Werror -Wextra

RM = rm -f

CC  = gcc

OBJ += $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) -pthread

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
