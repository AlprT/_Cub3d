/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_ccolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:19:50 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:19:50 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

static void	is_valid_comma(t_cub3d *cub3d)
{
	int	ct;
	int	i;

	ct = 0;
	i = 0;
	while (cub3d->data->ceiling_color->string[i] != '\0')
	{
		if (cub3d->data->ceiling_color->string[i] == ',')
			ct++;
		i++;
	}
	if (ct != 2)
		err(cub3d, "Invalid C color format. (R,G,B)");
}

static void	is_valid_red_color(t_cub3d *cub3d)
{
	char	*red_string;
	int		red;
	int		red_len;
	int		i;

	red_string = cub3d->data->ceiling_color->red_string;
	red_len = ft_strlen(red_string);
	if (red_len == 0)
		err(cub3d, "Red color of C can't be empty.");
	if (red_len > 3)
		err(cub3d, "Red color of C must be between \
			1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < red_len)
	{
		if (!ft_isdigit(red_string[i]))
			err(cub3d, "Red color of C must consist \
			of digit only. (0 - 9)");
		i++;
	}
	red = ft_atoi(red_string);
	if (red < 0 || red > 255)
		err(cub3d, "Red color of C must be a value between 0-255.");
	cub3d->data->ceiling_color->red = red;
}

static void	is_valid_green_color(t_cub3d *cub3d)
{
	char	*green_string;
	int		green;
	int		green_len;
	int		i;

	green_string = cub3d->data->ceiling_color->green_string;
	green_len = ft_strlen(green_string);
	if (green_len == 0)
		err(cub3d, "Green color of C can't be empty.");
	if (green_len > 3)
		err(cub3d, "Green color of C must be between \
		1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < green_len)
	{
		if (!ft_isdigit(green_string[i]))
			err(cub3d, "Green color of C must consist \
			of digit only. (0 - 9)");
		i++;
	}
	green = ft_atoi(green_string);
	if (green < 0 || green > 255)
		err(cub3d, "Green color of C must be a value between 0-255.");
	cub3d->data->ceiling_color->green = green;
}

static void	is_valid_blue_color(t_cub3d *cub3d)
{
	char	*blue_string;
	int		blue;
	int		blue_len;
	int		i;

	blue_string = cub3d->data->ceiling_color->blue_string;
	blue_len = ft_strlen(blue_string);
	if (blue_len == 0)
		err(cub3d, "Blue color of C can't be empty.");
	if (blue_len > 3)
		err(cub3d, "Blue color of C must be between \
		1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < blue_len)
	{
		if (!ft_isdigit(blue_string[i]))
			err(cub3d, "Blue color of C must consist \
			of digit only. (0 - 9)");
		i++;
	}
	blue = ft_atoi(blue_string);
	if (blue < 0 || blue > 255)
		err(cub3d, "Blue color of C must be a value between 0-255.");
	cub3d->data->ceiling_color->blue = blue;
}

void	is_valid_ccolor(t_cub3d *cub3d, char *line)
{
	char	**rgb;

	rgb = NULL;
	if (line[0] == 'C')
	{
		cub3d->data->ceiling_color->string = \
			trim_left(line + 1, " \t");
		if (*cub3d->data->ceiling_color->string == '\0')
			err(cub3d, "C element cant' be empty.");
		is_valid_comma(cub3d);
		rgb = ft_split(cub3d->data->ceiling_color->string, ',');
		cub3d->data->ceiling_color->red_string = ft_strdup(rgb[0]);
		cub3d->data->ceiling_color->green_string = ft_strdup(rgb[1]);
		cub3d->data->ceiling_color->blue_string = ft_strdup(rgb[2]);
		free_2darray(rgb);
		is_valid_red_color(cub3d);
		is_valid_green_color(cub3d);
		is_valid_blue_color(cub3d);
	}
}
