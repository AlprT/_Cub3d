/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:47 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:47 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data(t_cub3d *cub3d, int ac, char *fn)
{
	cub3d->data = malloc(sizeof(t_data));
	if (cub3d->data == NULL)
		err(cub3d, "data malloc error.");
	cub3d->data->ac = ac;
	cub3d->data->fn = fn;
	cub3d->data->text = NULL;
	cub3d->data->total_line_ct = 0;
	cub3d->data->full_line_ct = 0;
	cub3d->data->empty_line_ct = 0;
	cub3d->data->xpm = NULL;
	cub3d->data->floor_color = NULL;
	cub3d->data->ceiling_color = NULL;
	cub3d->data->map = NULL;
}

void	free_data(t_cub3d *cub3d)
{
	if (cub3d->data == NULL)
		return ;
	free_map(cub3d);
	free_colors(cub3d);
	free_xpm(cub3d);
	free_2darray(cub3d->data->text);
	free(cub3d->data);
}

