NAME        = so_long
BONUS_NAME  = so_long_bonus

CC          = cc
INCLUDE     = -I./include -I$(LIBFT_DIR) -I$(MLX_DIR)
CFLAGS      = -g -Wall -Wextra -Werror $(INCLUDE)

LIBFT_DIR   = libft
LIBFT       = -L$(LIBFT_DIR) -lft

MLX_DIR	= minilibx_macos
MLX		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

ifeq ($(shell uname -s), Linux)
	MLX_DIR	= minilibx-linux
	MLX		= -L$(MLX_DIR) -lmlx -lm -lX11 -lXext
endif


SRC_DIR     = src
OBJ_DIR     = obj

BONUS_SRC_DIR = bonus_src
BONUS_OBJ_DIR = bonus_obj

SRC_FILES = main.c check_maps.c image_settings.c helper_settings.c map_settings.c directions.c \
			directions1.c pars.c clean.c initializer.c

BONUS_SRC_FILES = main_bonus.c check_maps_bonus.c image_settings_bonus.c helper_settings_bonus.c map_settings_bonus.c directions_bonus.c \
            directions1_bonus.c pars_bonus.c clean_bonus.c initializer_bonus.c move_charachters_bonus.c 

SRC        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

BONUS_SRC  = $(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC_FILES))
BONUS_OBJ  = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRC_FILES:.c=.o))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): mlx lib $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(BONUS_NAME): mlx lib $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(MLX) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

lib:
	@make -C $(LIBFT_DIR)

mlx:
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re lib mlx
