/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:08:51 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 15:10:06 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_xpm(t_cub3d *cub3d)
{
	cub3d->data->xpm = malloc(sizeof(t_xpm));
	if (cub3d->data->xpm == NULL)
		err(cub3d, "xpm malloc error.");
	cub3d->data->xpm->north = NULL;
	cub3d->data->xpm->south = NULL;
	cub3d->data->xpm->west = NULL;
	cub3d->data->xpm->east = NULL;
	cub3d->data->xpm->north_ct = 0;
	cub3d->data->xpm->south_ct = 0;
	cub3d->data->xpm->west_ct = 0;
	cub3d->data->xpm->east_ct = 0;
}

void	free_xpm(t_cub3d *cub3d)
{
	if (cub3d->data->xpm == NULL)
		return ;
	if (cub3d->data->xpm->north != NULL)
		free(cub3d->data->xpm->north);
	if (cub3d->data->xpm->south != NULL)
		free(cub3d->data->xpm->south);
	if (cub3d->data->xpm->west != NULL)
		free(cub3d->data->xpm->west);
	if (cub3d->data->xpm->east != NULL)
		free(cub3d->data->xpm->east);
	free(cub3d->data->xpm);
}
