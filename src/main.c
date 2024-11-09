/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:29 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:29 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = init_cub3d(argc, argv[1]);
	check_args(cub3d);
	is_blackhole(cub3d);
	set_data_line_ct(cub3d);
	set_data_string(cub3d);
	check_elements(cub3d);
	set_map_string(cub3d);
	check_map(cub3d);
	init_game(cub3d);
	raycaster(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->screen->img, 0, 0);
	mlx_hook(cub3d->game->window, DESTROY, 0, destroy_handler, cub3d);
	mlx_hook(cub3d->game->window, KEYDOWN, 1L << 0, keydown_handler, cub3d);
	mlx_hook(cub3d->game->window, KEYUP, 1L << 1, keyup_handler, cub3d);
	mlx_loop_hook(cub3d->game->mlx, loop_handler, cub3d);
	mlx_loop(cub3d->game->mlx);
	return (0);
}
