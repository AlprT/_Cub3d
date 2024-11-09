/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:34 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:34 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_SPEED 0.075
# define TURN_SPEED 0.05

# define KEYDOWN 2
# define KEYUP 3
# define DESTROY 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# include <stdlib.h>

typedef struct s_xpm
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		north_ct;
	int		south_ct;
	int		west_ct;
	int		east_ct;
}			t_xpm;

typedef struct s_color
{
	char	*red_string;
	char	*green_string;
	char	*blue_string;
	char	*string;

	int		ct;
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_map
{
	char	**text;
	int		start_line;
	int		row_ct;
	int		col_ct;

	int		player_ct;
	int		player_row;
	int		player_col;
}			t_map;

typedef struct s_data
{
	int			ac;
	char		*fn;

	char		**text;
	int			total_line_ct;
	int			full_line_ct;
	int			empty_line_ct;

	t_xpm	*xpm;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_map		*map;
}				t_data;

typedef struct s_vector_double
{
	double	x;
	double	y;
}			t_vector_double;

typedef struct s_vector_int
{
	int	x;
	int	y;
}		t_vector_int;

typedef struct s_player
{
	t_vector_double	pos;
	t_vector_double	direction;
	t_vector_double	camera_plane;
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_keys;

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx_img;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_mlx_img	*screen;
	t_mlx_img	*north_img;
	t_mlx_img	*south_img;
	t_mlx_img	*west_img;
	t_mlx_img	*east_img;
	int			frgb;
	int			crgb;
	t_keys		keys;
	t_player	*player;
}				t_game;

typedef struct s_cub3d
{
	t_data	*data;
	t_game		*game;
}				t_cub3d;

typedef struct s_screen
{
	long	wall_height;
	int		wall_start_point;
	int		wall_end_point;
	int		hit_point_wall_texture;
	double	texture_offset_y;
	double	texture_pixel_ratio;
}			t_screen;

typedef struct s_ray
{
	t_vector_int	map_pos;
	t_vector_double	real_pos;
	t_vector_double	direction;
	t_vector_double	side_dist;
	t_vector_double	next_hit_dist;
	t_vector_int	map_step;
	int				hit_wall;
	char			hit_wall_side;
	double			view_of_wall;
	double			hit_point_wall;
	t_screen		screen;
}					t_ray;

void	init_data(t_cub3d *cub3d, int ac, char *fn);
void	free_data(t_cub3d *cub3d);
void	init_xpm(t_cub3d *cub3d);
void	free_xpm(t_cub3d *cub3d);
void	init_colors(t_cub3d *cub3d);
void	free_colors(t_cub3d *cub3d);
void	init_map(t_cub3d *cub3d);
void	free_map(t_cub3d *cub3d);
void	check_args(t_cub3d *cub3d);
void	is_blackhole(t_cub3d *cub3d);
void	set_data_line_ct(t_cub3d *cub3d);
void	set_data_string(t_cub3d *cub3d);
void	set_element_ct(t_cub3d *cub3d);
void	check_elements(t_cub3d *cub3d);
void	is_valid_xpm(t_cub3d *cub3d, char *line);
void	is_valid_fcolor(t_cub3d *cub3d, char *line);
void	is_valid_ccolor(t_cub3d *cub3d, char *line);
void	set_map_string(t_cub3d *cub3d);
char	**create_map_same_row_len(t_cub3d *cub3d);
void	check_map_empty_line(t_cub3d *cub3d);
void	check_map_characters(t_cub3d *cub3d);
void	check_map_walls(t_cub3d *cub3d);
void	check_map_whitespaces(t_cub3d *cub3d);
void	check_map(t_cub3d *cub3d);
char	*get_next_line(t_cub3d *cub3d, int fd);
int		is_empty(char *line);

void	init_game(t_cub3d *cub3d);
void	free_game(t_cub3d *cub3d);
void	init_mlx(t_cub3d *cub3d);
void	free_mlx(t_cub3d *cub3d);
void	init_screen(t_cub3d *cub3d);
void	free_screen(t_cub3d *cub3d);
void	init_north_mlx_img(t_cub3d *cub3d);
void	init_south_mlx_img(t_cub3d *cub3d);
void	init_west_mlx_img(t_cub3d *cub3d);
void	init_east_mlx_img(t_cub3d *cub3d);
void	init_crgb(t_cub3d *cub3d);
void	init_frgb(t_cub3d *cub3d);
void	free_xpm_imgs(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
void	free_player(t_cub3d *cub3d);

void	ray_settings(t_ray *ray, t_player *player, int x);
void	ray_hit_wall(t_ray *ray, t_map *map);
void	ray_wall_settings(t_ray *ray, t_player *player);
void	ray_tex_settings(t_ray *ray);
void	render_ray(t_ray *ray, t_game *game, int x);
void	raycaster(t_cub3d *cub3d);

void	player_move_up(t_map *map, t_player *player);
void	player_move_down(t_map *map, t_player *player);
void	player_move_left(t_map *map, t_player *player);
void	player_move_right(t_map *map, t_player *player);
void	player_turn_left(t_player *player);
void	player_turn_right(t_player *player);

size_t	get_img_color(t_mlx_img *img, int x, int y);
void	put_pixel_to_mlx_img(t_mlx_img *img, int x, int y, int color);
int		destroy_handler(t_cub3d *cub3d);
int		keydown_handler(int key, t_cub3d *cub3d);
int		keyup_handler(int key, t_cub3d *cub3d);
int		loop_handler(t_cub3d *cub3d);

t_cub3d	*init_cub3d(int ac, char *fn);
void	free_cub3d(t_cub3d *cub3d);
void	err(t_cub3d *cub3d, char *message);

void	free_2darray(char **ptr);
char	*trim_left(char *s1, char *set);

#endif