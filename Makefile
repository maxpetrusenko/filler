NAME = mpetruse.filler
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRC = 	*.c
HEADERS = filler.h
LIBFT = libft/libft.a
OBJ=$(SRC:.c=.o)
GREEN = \033[1;32m

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
		Make -C libft
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) 
		@echo "$(GREEN)Project successfully compiled"

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)
$(LIBFT):
		make -C libft

.PHONY : clean fclean re

clean :
		-rm -f $(OBJ)
		make clean -C libft
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		make fclean -C libft
		-rm -f libft/libft.a
		-rm -f $(NAME)
		@echo "$(GREEN)Cleaned everything"

re : fclean all