/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_same_row_len.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:25 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:25 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

char	**create_map_same_row_len(t_cub3d *cub3d)
{
	t_data	*data;
	char	**map;
	int		i;

	data = cub3d->data;
	map = malloc(sizeof(char *) * (data->map->row_ct + 1));
	if (map == NULL)
		err(cub3d, "create_map_same_row_len malloc error.");
	i = 0;
	while (data->map->text[i] != NULL)
	{
		map[i] = malloc(data->map->col_ct + 1);
		if (map[i] == NULL)
		{
			free_2darray(map);
			err(cub3d, "create_map_same_row_len malloc error.");
		}
		ft_strncpy(map[i], data->map->text[i], data->map->col_ct);
		i++;
	}
	map[i] = NULL;
	return (map);
}
