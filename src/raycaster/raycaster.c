/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:06 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:06 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycaster(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;

	ray.real_pos.x = cub3d->game->player->pos.x;
	ray.real_pos.y = cub3d->game->player->pos.y;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray_settings(&ray, cub3d->game->player, x);
		ray_hit_wall(&ray, cub3d->data->map);
		ray_wall_settings(&ray, cub3d->game->player);
		ray_tex_settings(&ray);
		render_ray(&ray, cub3d->game, x);
		x++;
	}
}
