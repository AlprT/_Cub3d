/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:59 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:59 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	set_data_string(t_cub3d *cub3d)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(cub3d->data->fn, O_RDONLY);
	if (fd == -1)
		err(cub3d, "An error occurred while opening the map file.");
	cub3d->data->text = malloc(
			sizeof(char *) * (cub3d->data->full_line_ct + 1));
	if (cub3d->data->text == NULL)
		err(cub3d, "data->text malloc error.");
	cub3d->data->text[cub3d->data->full_line_ct] = NULL;
	i = 0;
	while (i < cub3d->data->full_line_ct)
	{
		line = get_next_line(cub3d, fd);
		if (!is_empty(line))
		{
			cub3d->data->text[i] = line;
			i++;
		}
		else
			free(line);
	}
	close(fd);
}
