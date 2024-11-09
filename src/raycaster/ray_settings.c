/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:14 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:14 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

static void	side_dist_and_step(t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->map_step.x = -1;
		ray->side_dist.x = (ray->real_pos.x
				- ray->map_pos.x) * ray->next_hit_dist.x;
	}
	else
	{
		ray->map_step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0
				- ray->real_pos.x) * ray->next_hit_dist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->map_step.y = -1;
		ray->side_dist.y = (ray->real_pos.y
				- ray->map_pos.y) * ray->next_hit_dist.y;
	}
	else
	{
		ray->map_step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0
				- ray->real_pos.y) * ray->next_hit_dist.y;
	}
}

void	ray_settings(t_ray *ray, t_player *player, int x)
{
	double	normalized_camera_x;

	normalized_camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->direction.x = player->direction.x
		+ player->camera_plane.x * normalized_camera_x;
	ray->direction.y = player->direction.y
		+ player->camera_plane.y * normalized_camera_x;
	ray->next_hit_dist.x = fabs(1 / ray->direction.x);
	ray->next_hit_dist.y = fabs(1 / ray->direction.y);
	ray->map_pos.x = (int)player->pos.x;
	ray->map_pos.y = (int)player->pos.y;
	ray->hit_wall = 0;
	side_dist_and_step(ray);
}
