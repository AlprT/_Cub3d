/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:20:09 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:20:09 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

static void	check_unknown_element(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->data->text[i];
		if (ft_strncmp("NO", line, 2) != 0 && ft_strncmp("SO", line, 2) != 0
			&& ft_strncmp("WE", line, 2) != 0 && ft_strncmp("EA", line, 2) != 0
			&& ft_strncmp("F", line, 1) != 0 && ft_strncmp("C", line, 1) != 0)
		{
			err(cub3d, "Unrecognized element on the file.");
		}
		i++;
	}
}

static void	check_multiple_element(t_cub3d *cub3d)
{
	t_data	*data;

	data = cub3d->data;
	if (data->xpm->north_ct > 1)
		err(cub3d, "NO element type cannot be more than 1.");
	if (data->xpm->south_ct > 1)
		err(cub3d, "SO element type cannot be more than 1.");
	if (data->xpm->west_ct > 1)
		err(cub3d, "WE element type cannot be more than 1.");
	if (data->xpm->east_ct > 1)
		err(cub3d, "EA element type cannot be more than 1.");
	if (data->floor_color->ct > 1)
		err(cub3d, "F element type cannot be more than 1.");
	if (data->ceiling_color->ct > 1)
		err(cub3d, "C element type cannot be more than 1.");
}

static void	is_valid_different_xpm(t_cub3d *cub3d)
{
	t_data	*data;

	data = cub3d->data;
	if (ft_strcmp(data->xpm->north, data->xpm->south) == 0
		|| ft_strcmp(data->xpm->north, data->xpm->west) == 0
		|| ft_strcmp(data->xpm->north, data->xpm->east) == 0)
		err(cub3d, "NO texture can't be used for other textures.");
	if (ft_strcmp(data->xpm->south, data->xpm->north) == 0
		|| ft_strcmp(data->xpm->south, data->xpm->west) == 0
		|| ft_strcmp(data->xpm->south, data->xpm->east) == 0)
		err(cub3d, "SO texture can't be used for other textures.");
	if (ft_strcmp(data->xpm->west, data->xpm->north) == 0
		|| ft_strcmp(data->xpm->west, data->xpm->south) == 0
		|| ft_strcmp(data->xpm->west, data->xpm->east) == 0)
		err(cub3d, "WE texture can't be used for other textures.");
	if (ft_strcmp(data->xpm->east, data->xpm->south) == 0
		|| ft_strcmp(data->xpm->east, data->xpm->north) == 0
		|| ft_strcmp(data->xpm->east, data->xpm->west) == 0)
		err(cub3d, "EA texture can't be used for other textures.");
}

static void	is_valid_different_color(t_cub3d *cub3d)
{
	t_data	*data;

	data = cub3d->data;
	if (data->floor_color->red == data->ceiling_color->red
		&& data->floor_color->green == data->ceiling_color->green
		&& data->floor_color->blue == data->ceiling_color->blue)
	{
		err(cub3d, "Floor and ceiling color should not be the same.");
	}
}

void	check_elements(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	set_element_ct(cub3d);
	check_unknown_element(cub3d);
	check_multiple_element(cub3d);
	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->data->text[i];
		is_valid_xpm(cub3d, line);
		is_valid_fcolor(cub3d, line);
		is_valid_ccolor(cub3d, line);
		i++;
	}
	is_valid_different_xpm(cub3d);
	is_valid_different_color(cub3d);
}
