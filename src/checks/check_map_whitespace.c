/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_whitespace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:19:58 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:19:58 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	err_free(t_cub3d *cub3d, char **map)
{
	free_2darray(map);
	err(cub3d, "Rouge space character in the map.");
}

static int	valid_char(char chr)
{
	if (chr == '1' || chr == ' ' || chr == '\0')
		return (1);
	return (0);
}

static void	is_valid_row_spaces(t_cub3d *cub3d, char **map, int last_row_index)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == ' ')
			{
				if (row == 0 && !valid_char(map[row + 1][col]))
					err_free(cub3d, map);
				if (row == last_row_index && !valid_char(map[row - 1][col]))
					err_free(cub3d, map);
				if (row > 0 && row < last_row_index
					&& (!valid_char(map[row - 1][col])
					|| !valid_char(map[row + 1][col])))
					err_free(cub3d, map);
			}
			col++;
		}
		row++;
	}
}

static void	is_valid_col_spaces(t_cub3d *cub3d, char **map, int last_col_index)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == ' ')
			{
				if (col == 0 && !valid_char(map[row][col + 1]))
					err_free(cub3d, map);
				if (col == last_col_index && !valid_char(map[row][col - 1]))
					err_free(cub3d, map);
				if (col > 0 && col < last_col_index
					&& (!valid_char(map[row][col - 1])
					|| !valid_char(map[row][col + 1])))
					err_free(cub3d, map);
			}
			col++;
		}
		row++;
	}
}

void	check_map_whitespaces(t_cub3d *cub3d)
{
	char	**map;
	int		last_row_index;
	int		last_col_index;

	map = create_map_same_row_len(cub3d);
	last_row_index = cub3d->data->map->row_ct - 1;
	last_col_index = cub3d->data->map->col_ct - 1;
	is_valid_row_spaces(cub3d, map, last_row_index);
	is_valid_col_spaces(cub3d, map, last_col_index);
	free_2darray(map);
}
