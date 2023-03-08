NAME = so_long
CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = $(CFLAGS) -I$(HEADERS_DIR)/headers
CONFIG_DIR = ./config
UTILS_DIR = ./utils
GNL_DIR = ./utils/getnextline
HEADERS_DIR = ./headers
SRCS = so_long.c $(GNL_DIR)/get_next_line_utils.c $(GNL_DIR)/get_next_line.c $(UTILS_DIR)/utils.c $(UTILS_DIR)/ft_printf.c $(UTILS_DIR)/subs.c $(UTILS_DIR)/get_conversion.c $(UTILS_DIR)/print_numbers.c $(UTILS_DIR)/printf_characters.c $(CONFIG_DIR)/constraints.c $(CONFIG_DIR)/controls.c $(CONFIG_DIR)/envirment.c 
OBJ = $(SRCS:%.c=%.o)

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all: $(OBJ)
	make -C $(MINILIBX)
	$(CC) $(FLAGS) $(OBJ) $(LIBRARY) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	make clean -C $(MINILIBX)
	rm -f $(NAME)
	
re: fclean all

.PHONY: all $(NAME) clean fclean re
