/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element_ct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:56 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:56 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void	set_element_ct(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->data->text[i];
		if (ft_strncmp("NO", line, 2) == 0)
			cub3d->data->xpm->north_ct++;
		if (ft_strncmp("SO", line, 2) == 0)
			cub3d->data->xpm->south_ct++;
		if (ft_strncmp("WE", line, 2) == 0)
			cub3d->data->xpm->west_ct++;
		if (ft_strncmp("EA", line, 2) == 0)
			cub3d->data->xpm->east_ct++;
		if (ft_strncmp("F", line, 1) == 0)
			cub3d->data->floor_color->ct++;
		if (ft_strncmp("C", line, 1) == 0)
			cub3d->data->ceiling_color->ct++;
		i++;
	}
}
