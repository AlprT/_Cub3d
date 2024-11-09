/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blackhole.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:19:53 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:19:53 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	is_blackhole(t_cub3d *cub3d)
{
	char	character;
	int		readed_byte;
	int		fd;

	character = '\0';
	readed_byte = 0;
	fd = open(cub3d->data->fn, O_RDONLY);
	if (fd == -1)
		err(cub3d, "An error occurred while opening the map file.");
	readed_byte = read(fd, &character, 1);
	if (readed_byte == -1)
		err(cub3d, "An error occurred while reading the map file.");
	if (readed_byte == 0)
		err(cub3d, "Empty map file.");
	close(fd);
}
