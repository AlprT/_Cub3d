/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:49 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:49 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_cub3d	*init_cub3d(int ac, char *fn)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (cub3d == NULL)
		err(cub3d, "cub3d malloc error.");
	init_data(cub3d, ac, fn);
	init_xpm(cub3d);
	init_colors(cub3d);
	init_map(cub3d);
	cub3d->game = NULL;
	return (cub3d);
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d == NULL)
		return ;
	free_data(cub3d);
	free_game(cub3d);
	free(cub3d);
}
