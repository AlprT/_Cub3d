/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:54 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:54 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void	set_map_string(t_cub3d *cub3d)
{
	t_data	*data;
	int		map_index;
	int		col_ct;
	int		i;

	data = cub3d->data;
	map_index = 6;
	data->map->row_ct = data->full_line_ct - map_index;
	data->map->text = malloc(sizeof(char *) * (data->map->row_ct + 1));
	if (data->map->text == NULL)
		err(cub3d, "data->map->text malloc error.");
	col_ct = 0;
	i = 0;
	while (data->text[map_index] != NULL)
	{
		data->map->text[i] = ft_strdup(data->text[map_index]);
		col_ct = ft_strlen(data->text[map_index]);
		if (col_ct > data->map->col_ct)
			data->map->col_ct = col_ct;
		i++;
		map_index++;
	}
	data->map->text[i] = NULL;
}
