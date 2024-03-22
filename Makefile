# Name of the executable
NAME = push_swap
NAME2 = checker

# Compiler
CC = gcc 
# gcc -g -o so_long so_long.c
# Compiler flags
#CFLAGS = -Wall -Wextra -Werror -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-unused-parameter -Wno-unused-variable -Wno-sign-compare
CFLAGS := -Wall -Wextra -Werror -g -Iheaders/ 
# Include paths for header files

# Libraries to link against, including the math library if needed
#LDLIBS := -lft -lftprintf
LDLIBS := -framework OpenGL -framework AppKit -lm 

# Source files
SRC = $(wildcard *.c) \
		$(wildcard libft/ft_*.c) \
		$(wildcard printf/ft_*.c) \

SRC_BONUS = $(wildcard bonus/bonus_*.c) \
			$(wildcard printf/ft*.c) \
			$(wildcard libft/ft_*.c) \
			$(wildcard gnl/ft_*.c)
# SRC := $(wildcard src/*.c)
# Object files
OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC_BONUS:.c=.o)

# Phony targets for make commands
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Rule to link the program
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDLIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME2)

# Rule to link the program
$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) $(LDLIBS) -o $(NAME2)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#
# Rule to clean object files and other temporary files
clean:
	rm -f $(OBJ) $(NAME)

# Rule to fully clean the project, including the executable
fclean: clean
	rm -f $(NAME)

clean_bonus:
	rm -f $(OBJ2) $(NAME2)

# Rule to fully clean the project, including the executable
fclean_bonus: clean
	rm -f $(NAME2)

# Rule to re-make the project
re: fclean all

re2: fclean_bonus bonus
