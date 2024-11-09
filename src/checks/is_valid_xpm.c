/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:19:46 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:19:46 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

static void	is_valid_north_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("NO", line, 2) == 0)
	{
		data->xpm->north = trim_left(line + 2, " \t");
		if (data->xpm->north[0] == '\0')
			err(cub3d, "NO element can't be null.");
		if (ft_strcmp(data->xpm->north
				+ ft_strlen(data->xpm->north) - 4, ".xpm") != 0)
			err(cub3d, "NO element must end with the .xpm extension.");
		fd = open(data->xpm->north, O_RDONLY);
		if (fd == -1)
			err(cub3d, "NO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	is_valid_south_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("SO", line, 2) == 0)
	{
		data->xpm->south = trim_left(line + 2, " \t");
		if (data->xpm->south[0] == '\0')
			err(cub3d, "SO element cant' be empty.");
		if (ft_strcmp(data->xpm->south
				+ ft_strlen(data->xpm->south) - 4, ".xpm") != 0)
			err(cub3d, "SO element must end with the .xpm extension.");
		fd = open(data->xpm->south, O_RDONLY);
		if (fd == -1)
			err(cub3d, "SO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	is_valid_west_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("WE", line, 2) == 0)
	{
		data->xpm->west = trim_left(line + 2, " \t");
		if (data->xpm->west[0] == '\0')
			err(cub3d, "WE element cant' be empty.");
		if (ft_strcmp(data->xpm->west
				+ ft_strlen(data->xpm->west) - 4, ".xpm") != 0)
			err(cub3d, "WE element must end with the .xpm extension.");
		fd = open(data->xpm->west, O_RDONLY);
		if (fd == -1)
			err(cub3d, "WE xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	is_valid_east_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("EA", line, 2) == 0)
	{
		data->xpm->east = trim_left(line + 2, " \t");
		if (data->xpm->east[0] == '\0')
			err(cub3d, "EA element cant' be empty.");
		if (ft_strcmp(data->xpm->east
				+ ft_strlen(data->xpm->east) - 4, ".xpm") != 0)
			err(cub3d, "EA element must end with the .xpm extension.");
		fd = open(data->xpm->east, O_RDONLY);
		if (fd == -1)
			err(cub3d, "EA xpm file not found or can't be opened.");
		close(fd);
	}
}

void	is_valid_xpm(t_cub3d *cub3d, char *line)
{
	is_valid_north_xpm(cub3d, line);
	is_valid_south_xpm(cub3d, line);
	is_valid_west_xpm(cub3d, line);
	is_valid_east_xpm(cub3d, line);
}
