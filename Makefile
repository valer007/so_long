NAME	= so_long

CC		= cc
INCLUDE = -I./include
CFLAGS	= -Wall -Wextra -Werror $(INCLUDE)
SRC_DIR	= .
OBJ_DIR	= obj

SRC		= main.c
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

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
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

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
