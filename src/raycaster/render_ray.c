/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:04 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:04 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_mlx_img	*get_wall_texture(t_ray *ray, t_game *game)
{
	t_mlx_img	*wall_texture;
	t_player	*player;

	player = game->player;
	wall_texture = NULL;
	if (ray->hit_wall_side == 'x')
	{
		if (ray->map_pos.x < player->pos.x)
			wall_texture = game->east_img;
		else
			wall_texture = game->west_img;
	}
	else if (ray->hit_wall_side == 'y')
	{
		if (ray->map_pos.y < player->pos.y)
			wall_texture = game->south_img;
		else
			wall_texture = game->north_img;
	}
	return (wall_texture);
}

void	render_ray(t_ray *ray, t_game *game, int x)
{
	t_mlx_img	*wall_texture;
	double		texture_offset_y;
	double		texture_offset_x;
	int			texture_color;
	int			y;

	wall_texture = get_wall_texture(ray, game);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < ray->screen.wall_start_point)
			put_pixel_to_mlx_img(game->screen, x, y, game->crgb);
		else if (y > ray->screen.wall_end_point)
			put_pixel_to_mlx_img(game->screen, x, y, game->frgb);
		else
		{
			texture_offset_y = (int)ray->screen.texture_offset_y & (64 - 1);
			texture_offset_x = ray->screen.hit_point_wall_texture;
			texture_color = get_img_color(wall_texture,
					texture_offset_x, texture_offset_y);
			put_pixel_to_mlx_img(game->screen, x, y, texture_color);
			ray->screen.texture_offset_y += ray->screen.texture_pixel_ratio;
		}
		y++;
	}
}
