/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:32 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:32 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_crgb(t_cub3d *cub3d)
{
	int	red;
	int	green;
	int	blue;

	red = cub3d->data->ceiling_color->red;
	green = cub3d->data->ceiling_color->green;
	blue = cub3d->data->ceiling_color->blue;
	cub3d->game->crgb = (red << 16 | green << 8 | blue);
}

void	init_frgb(t_cub3d *cub3d)
{
	int	red;
	int	green;
	int	blue;

	red = cub3d->data->floor_color->red;
	green = cub3d->data->floor_color->green;
	blue = cub3d->data->floor_color->blue;
	cub3d->game->frgb = (red << 16 | green << 8 | blue);
}
