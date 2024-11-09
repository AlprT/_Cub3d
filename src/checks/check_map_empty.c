/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:20:04 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:20:04 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	check_map_empty_line(t_cub3d *cub3d)
{
	t_data	*data;
	char	*line;
	int		i;
	int		fd;

	data = cub3d->data;
	fd = open(data->fn, O_RDONLY);
	if (fd == -1)
		err(cub3d, "An error occurred while opening the map file.");
	line = NULL;
	i = 1;
	while (i <= data->total_line_ct)
	{
		line = get_next_line(cub3d, fd);
		if (is_empty(line) && i > data->map->start_line)
		{
			free(line);
			err(cub3d,
				"Empty line in the map is not allowed.");
		}
		free(line);
		i++;
	}
	close(fd);
}
