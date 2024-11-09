/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:29 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:29 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../mlx/mlx.h"

void	init_screen(t_cub3d *cub3d)
{
	t_game	*game;

	game = cub3d->game;
	game->screen = malloc(sizeof(t_mlx_img));
	if (game->screen == NULL)
		err(cub3d, "game->screen malloc error.");
	game->screen->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->screen->img == NULL)
		err(cub3d, "game->screen->img malloc error.");
	game->screen->addr = mlx_get_data_addr(game->screen->img,
			&game->screen->bits_per_pixel,
			&game->screen->size_line,
			&game->screen->endian);
	if (game->screen->addr == NULL)
		err(cub3d, "game->screen->addr malloc error.");
}

void	free_screen(t_cub3d *cub3d)
{
	if (cub3d->game->screen == NULL)
		return ;
	if (cub3d->game->screen->img != NULL)
		mlx_destroy_image(cub3d->game->mlx, cub3d->game->screen->img);
	free(cub3d->game->screen);
}
