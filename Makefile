NAME = Cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ./src/main.c \
./src/checks/check_args.c \
./src/checks/check_map_empty.c \
./src/checks/is_valid_ccolor.c \
./src/checks/check_elements.c \
./src/checks/check_map_walls.c \
./src/checks/is_valid_fcolor.c \
./src/checks/check_map.c \
./src/checks/check_map_whitespace.c \
./src/checks/is_valid_xpm.c \
./src/checks/check_map_char.c \
./src/checks/is_blackhole.c \
./src/init/init_colors.c \
./src/init/init_data.c \
./src/init/init_map.c \
./src/init/init_mlx_img.c \
./src/init/init_rgb.c \
./src/init/init_cub3d.c \
./src/init/init_game.c \
./src/init/init_mlx.c \
./src/init/init_xpm.c \
./src/init/init_player.c \
./src/init/init_screen.c \
./src/mlx_handlers/mlx_event_handler.c \
./src/mlx_handlers/mlx_loop_handler.c \
./src/movement/move.c \
./src/movement/turn.c \
./src/raycaster/ray_hit_wall.c \
./src/raycaster/ray_tex_settings.c \
./src/raycaster/raycaster.c \
./src/raycaster/ray_settings.c \
./src/raycaster/ray_wall_settings.c \
./src/raycaster/render_ray.c \
./src/set/set_data_line_ct.c \
./src/set/set_element_ct.c \
./src/set/set_data_string.c \
./src/set/set_map_string.c \
./src/utils/err.c \
./src/utils/gnl.c \
./src/utils/mlx_utils.c \
./src/utils/free_2darray.c \
./src/utils/is_empty.c \
./src/utils/trim_left.c \
./src/create_map_same_row_len.c

OBJ = $(SRC:.c=.o)

MINILIBX = ./src/mlx

LIBFT_PATH = ./src/libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) mlx
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX) -lmlx -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

mlx:
	@make -C $(MINILIBX)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX)
	@clear

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX)
	@clear

re: fclean all

.PHONY: all clean fclean re