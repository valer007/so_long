NAME	= so_long

CC		= cc
INCLUDE = -I./include -I$(LIBFT_DIR) -I$(MLX_DIR)
CFLAGS	= -g -Wall -Wextra -Werror $(INCLUDE)

SRC_DIR	= src
OBJ_DIR	= obj

SRC_FILES = main.c check_maps.c image_settings.c helper_settings.c map_settings.c directions.c \
			directions1.c pars.c move_charachters.c clean.c initializer.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIBFT_DIR = libft
LIBFT	= -L$(LIBFT_DIR) -lft

MLX_DIR	= minilibx_macos
MLX		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

ifeq ($(shell uname -s), Linux)
	MLX_DIR	= minilibx-linux
	MLX		= -L$(MLX_DIR) -lmlx -lm -lX11 -lXext
endif

all: $(NAME)

$(NAME): mlx lib $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

lib:
	@make -C $(LIBFT_DIR)

mlx:
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re lib mlx
