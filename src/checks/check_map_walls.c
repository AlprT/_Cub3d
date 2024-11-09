/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:20:01 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:20:01 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

static void	err_free(t_cub3d *cub3d, char *line)
{
	free(line);
	err(cub3d, "The map must be closed/surrounded by walls.");
}

static void	check_map_border(t_cub3d *cub3d)
{
	char	*line;
	int		last_row_index;
	int		last_col_index;
	int		row;
	int		col;

	last_row_index = cub3d->data->map->row_ct - 1;
	row = 0;
	while (cub3d->data->map->text[row] != NULL)
	{
		line = ft_strtrim(cub3d->data->map->text[row], " ");
		last_col_index = ft_strlen(line) - 1;
		col = 0;
		while (line[col] != '\0')
		{
			if ((row == 0 || row == last_row_index) && line[col] == '0')
				err_free(cub3d, line);
			else if (line[0] == '0' || line[last_col_index] == '0')
				err_free(cub3d, line);
			col++;
		}
		free(line);
		row++;
	}
}

static void	dfs_algorithm(t_cub3d *cub3d, char **map, int row, int col)
{
	if (row < 0 || row >= cub3d->data->map->row_ct
		|| col < 0 || col >= cub3d->data->map->col_ct)
	{
		free_2darray(map);
		err(cub3d, "The map must be closed/surrounded by walls.");
	}
	if (map[row][col] == '1' || map[row][col] == '.')
		return ;
	map[row][col] = '.';
	dfs_algorithm(cub3d, map, row, col + 1);
	dfs_algorithm(cub3d, map, row, col - 1);
	dfs_algorithm(cub3d, map, row + 1, col);
	dfs_algorithm(cub3d, map, row - 1, col);
}

static void	get_player_pos(t_cub3d *cub3d, int *row, int *col)
{
	char	chr;
	int		r;
	int		c;

	chr = '\0';
	r = 0;
	while (cub3d->data->map->text[r] != NULL)
	{
		c = 0;
		while (cub3d->data->map->text[r][c] != '\0')
		{
			chr = cub3d->data->map->text[r][c];
			if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
			{
				*row = r;
				*col = c;
				return ;
			}
			c++;
		}
		r++;
	}
}

void	check_map_walls(t_cub3d *cub3d)
{
	char	**map;
	int		player_row;
	int		player_col;

	map = create_map_same_row_len(cub3d);
	get_player_pos(cub3d, &player_row, &player_col);
	dfs_algorithm(cub3d, map, player_row, player_col);
	free_2darray(map);
	check_map_border(cub3d);
}
