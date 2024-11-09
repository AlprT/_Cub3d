/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_line_ct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:01 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:01 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void	clear_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = '\0';
		i++;
	}
}

static void	handle_line(t_data *data, char *line, int readed_byte, int *i)
{
	if (line[*i] == '\n' || readed_byte == 0)
	{
		data->total_line_ct++;
		line[*i + 1] = '\0';
		if (!is_empty(line))
		{
			data->full_line_ct++;
			if (data->full_line_ct == 7)
				data->map->start_line = data->total_line_ct;
		}
		else
			data->empty_line_ct++;
		clear_line(line);
		*i = -1;
	}
}

void	set_data_line_ct(t_cub3d *cub3d)
{
	char	line[1024];
	char	character;
	int		readed_byte;
	int		i;
	int		fd;

	character = '\0';
	readed_byte = 1;
	i = 0;
	fd = open(cub3d->data->fn, O_RDONLY);
	if (fd == -1)
		err(cub3d, "An error occurred while opening the map file.");
	while (readed_byte > 0)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
			err(cub3d, "The map file could not be read.");
		line[i] = character;
		handle_line(cub3d->data, line, readed_byte, &i);
		i++;
	}
	close(fd);
	if (cub3d->data->full_line_ct < 9)
		err(cub3d, "There must be at least 9 text \
		in the datauration file. (4 texture, 2 color, min 3 for map)");
}
