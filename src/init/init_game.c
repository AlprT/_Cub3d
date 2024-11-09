/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:44 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:44 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_keys(t_cub3d *cub3d)
{
	cub3d->game->keys.w = 0;
	cub3d->game->keys.s = 0;
	cub3d->game->keys.a = 0;
	cub3d->game->keys.d = 0;
	cub3d->game->keys.left = 0;
	cub3d->game->keys.right = 0;
}

void	init_game(t_cub3d *cub3d)
{
	cub3d->game = malloc(sizeof(t_game));
	if (cub3d->game == NULL)
		err(cub3d, "game malloc error.");
	cub3d->game->mlx = NULL;
	cub3d->game->window = NULL;
	cub3d->game->screen = NULL;
	cub3d->game->player = NULL;
	cub3d->game->crgb = 0;
	cub3d->game->frgb = 0;
	init_mlx(cub3d);
	init_screen(cub3d);
	init_north_mlx_img(cub3d);
	init_south_mlx_img(cub3d);
	init_west_mlx_img(cub3d);
	init_east_mlx_img(cub3d);
	init_crgb(cub3d);
	init_frgb(cub3d);
	init_player(cub3d);
	init_keys(cub3d);
}

void	free_game(t_cub3d *cub3d)
{
	if (cub3d->game == NULL)
		return ;
	free_player(cub3d);
	free_xpm_imgs(cub3d);
	free_screen(cub3d);
	free_mlx(cub3d);
	free(cub3d->game);
}
