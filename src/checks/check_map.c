/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:19:55 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:19:55 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(t_cub3d *cub3d)
{
	check_map_empty_line(cub3d);
	check_map_characters(cub3d);
	check_map_walls(cub3d);
	check_map_whitespaces(cub3d);
}
