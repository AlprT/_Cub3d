/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:20:07 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:20:07 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	character_is_valid(char chr)
{
	if (chr != '0' && chr != '1'
		&& chr != 'N' && chr != 'S' && chr != 'W' && chr != 'E'
		&& chr != ' ')
	{
		return (0);
	}
	return (1);
}

static int	character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
		return (1);
	return (0);
}

static void	is_valid_player_pos(t_cub3d *cub3d)
{
	t_map	*map;

	map = cub3d->data->map;
	if (map->player_ct < 1)
		err(cub3d, "Player info not found");
	if (map->player_ct > 1)
		err(cub3d, "Excess player info found");
	if (map->player_row == 0 || map->player_row == map->row_ct - 1 
	|| map->player_col == 0 || map->player_col == map->col_ct - 1)
		err(cub3d, "Player is out of bounds.");
}

void	check_map_characters(t_cub3d *cub3d)
{
	t_map	*map;
	int		row;
	int		col;

	map = cub3d->data->map;
	row = 0;
	while (map->text[row] != NULL)
	{
		col = 0;
		while (map->text[row][col] != '\0')
		{
			if (!character_is_valid(map->text[row][col]))
				err(cub3d, "Unrecognized character in the map.");
			if (character_is_player(map->text[row][col]))
			{
				map->player_ct++;
				map->player_row = row;
				map->player_col = col;
			}
			col++;
		}
		row++;
	}
	is_valid_player_pos(cub3d);
}
