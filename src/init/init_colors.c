/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:52 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:52 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_colors(t_cub3d *cub3d)
{
	cub3d->data->floor_color = malloc(sizeof(t_color));
	if (cub3d->data->floor_color == NULL)
		err(cub3d, "floor_color malloc error.");
	cub3d->data->ceiling_color = malloc(sizeof(t_color));
	if (cub3d->data->ceiling_color == NULL)
		err(cub3d, "ceiling_color malloc error.");
	cub3d->data->floor_color->red = -1;
	cub3d->data->floor_color->green = -1;
	cub3d->data->floor_color->blue = -1;
	cub3d->data->floor_color->ct = 0;
	cub3d->data->floor_color->string = NULL;
	cub3d->data->floor_color->red_string = NULL;
	cub3d->data->floor_color->green_string = NULL;
	cub3d->data->floor_color->blue_string = NULL;
	cub3d->data->ceiling_color->red = -1;
	cub3d->data->ceiling_color->green = -1;
	cub3d->data->ceiling_color->blue = -1;
	cub3d->data->ceiling_color->ct = 0;
	cub3d->data->ceiling_color->string = NULL;
	cub3d->data->ceiling_color->red_string = NULL;
	cub3d->data->ceiling_color->green_string = NULL;
	cub3d->data->ceiling_color->blue_string = NULL;
}

void	free_colors(t_cub3d *cub3d)
{
	if (cub3d->data->floor_color != NULL)
	{
		if (cub3d->data->floor_color->string != NULL)
			free(cub3d->data->floor_color->string);
		if (cub3d->data->floor_color->red_string != NULL)
			free(cub3d->data->floor_color->red_string);
		if (cub3d->data->floor_color->green_string != NULL)
			free(cub3d->data->floor_color->green_string);
		if (cub3d->data->floor_color->blue_string != NULL)
			free(cub3d->data->floor_color->blue_string);
		free(cub3d->data->floor_color);
	}
	if (cub3d->data->ceiling_color != NULL)
	{
		if (cub3d->data->ceiling_color->string != NULL)
			free(cub3d->data->ceiling_color->string);
		if (cub3d->data->ceiling_color->red_string != NULL)
			free(cub3d->data->ceiling_color->red_string);
		if (cub3d->data->ceiling_color->green_string != NULL)
			free(cub3d->data->ceiling_color->green_string);
		if (cub3d->data->ceiling_color->blue_string != NULL)
			free(cub3d->data->ceiling_color->blue_string);
		free(cub3d->data->ceiling_color);
	}
}
