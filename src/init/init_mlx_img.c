/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:39 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:39 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../mlx/mlx.h"

void	init_north_mlx_img(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->north_img = malloc(sizeof(t_mlx_img));
	if (cub3d->game->north_img == NULL)
		err(cub3d, "north_img malloc error.");
	cub3d->game->north_img->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->data->xpm->north, &size, &size);
	if (cub3d->game->north_img->img == NULL)
		err(cub3d, "north_img->img malloc error.");
	cub3d->game->north_img->addr = mlx_get_data_addr(
			cub3d->game->north_img->img,
			&cub3d->game->north_img->bits_per_pixel,
			&cub3d->game->north_img->size_line,
			&cub3d->game->north_img->endian);
	if (cub3d->game->north_img->addr == NULL)
		err(cub3d, "north_img->addr malloc error.");
}

void	init_south_mlx_img(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->south_img = malloc(sizeof(t_mlx_img));
	if (cub3d->game->south_img == NULL)
		err(cub3d, "south_img malloc error.");
	cub3d->game->south_img->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->data->xpm->south, &size, &size);
	if (cub3d->game->south_img->img == NULL)
		err(cub3d, "south_img->img malloc error.");
	cub3d->game->south_img->addr = mlx_get_data_addr(
			cub3d->game->south_img->img,
			&cub3d->game->south_img->bits_per_pixel,
			&cub3d->game->south_img->size_line,
			&cub3d->game->south_img->endian);
	if (cub3d->game->south_img->addr == NULL)
		err(cub3d, "south_img->addr malloc error.");
}

void	init_west_mlx_img(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->west_img = malloc(sizeof(t_mlx_img));
	if (cub3d->game->west_img == NULL)
		err(cub3d, "west_img malloc error.");
	cub3d->game->west_img->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->data->xpm->west, &size, &size);
	if (cub3d->game->west_img->img == NULL)
		err(cub3d, "west_img->img malloc error.");
	cub3d->game->west_img->addr = mlx_get_data_addr(
			cub3d->game->west_img->img,
			&cub3d->game->west_img->bits_per_pixel,
			&cub3d->game->west_img->size_line,
			&cub3d->game->west_img->endian);
	if (cub3d->game->west_img->addr == NULL)
		err(cub3d, "west_img->addr malloc error.");
}

void	init_east_mlx_img(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->east_img = malloc(sizeof(t_mlx_img));
	if (cub3d->game->east_img == NULL)
		err(cub3d, "east_img malloc error.");
	cub3d->game->east_img->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->data->xpm->east, &size, &size);
	if (cub3d->game->east_img->img == NULL)
		err(cub3d, "east_img->img malloc error.");
	cub3d->game->east_img->addr = mlx_get_data_addr(
			cub3d->game->east_img->img,
			&cub3d->game->east_img->bits_per_pixel,
			&cub3d->game->east_img->size_line,
			&cub3d->game->east_img->endian);
	if (cub3d->game->east_img->addr == NULL)
		err(cub3d, "east_img->addr malloc error.");
}

void	free_xpm_imgs(t_cub3d *cub3d)
{
	if (cub3d->game->north_img != NULL)
	{
		if (cub3d->game->north_img->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->north_img->img);
		free(cub3d->game->north_img);
	}
	if (cub3d->game->south_img != NULL)
	{
		if (cub3d->game->south_img->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->south_img->img);
		free(cub3d->game->south_img);
	}
	if (cub3d->game->west_img != NULL)
	{
		if (cub3d->game->west_img->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->west_img->img);
		free(cub3d->game->west_img);
	}
	if (cub3d->game->east_img != NULL)
	{
		if (cub3d->game->east_img->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->east_img->img);
		free(cub3d->game->east_img);
	}
}
