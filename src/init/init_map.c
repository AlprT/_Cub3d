/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:42 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:42 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map(t_cub3d *cub3d)
{
	cub3d->data->map = malloc(sizeof(t_map));
	if (cub3d->data->map == NULL)
		err(cub3d, "map malloc error.");
	cub3d->data->map->text = NULL;
	cub3d->data->map->start_line = 0;
	cub3d->data->map->row_ct = 0;
	cub3d->data->map->col_ct = 0;
	cub3d->data->map->player_ct = 0;
	cub3d->data->map->player_row = 0;
	cub3d->data->map->player_col = 0;
}

void	free_map(t_cub3d *cub3d)
{
	if (cub3d->data->map == NULL)
		return ;
	free_2darray(cub3d->data->map->text);
	free(cub3d->data->map);
}
