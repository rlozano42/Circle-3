NAME = libasm.a

SRC = src/ft_write.s src/ft_strlen.s src/ft_strcmp.s src/ft_strcpy.s src/ft_read.s src/ft_strdup.s

OBJ = src/ft_write.o src/ft_strlen.o src/ft_strcmp.o src/ft_strcpy.o src/ft_read.o src/ft_strdup.o


all: $(NAME)

%.o: %.s
	@nasm -f macho64 $<

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: re
	@gcc -Wall -Wextra -Werror src/main.c $(NAME) -o test

.PHONY:  all clean fclean re test