/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tex_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:12 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:12 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_tex_settings(t_ray *ray)
{
	double	overflow_pixel_on_top;

	overflow_pixel_on_top = 0;
	ray->screen.texture_pixel_ratio = 1.0 * 64 / ray->screen.wall_height;
	ray->screen.texture_offset_y = 0;
	if (ray->screen.wall_height > SCREEN_HEIGHT)
	{
		overflow_pixel_on_top = (ray->screen.wall_height - SCREEN_HEIGHT) / 2;
		ray->screen.texture_offset_y = overflow_pixel_on_top
			* ray->screen.texture_pixel_ratio;
		ray->screen.wall_start_point = 0;
		ray->screen.wall_end_point = SCREEN_HEIGHT;
	}
}
