/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:52 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:52 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

void	err(t_cub3d *cub3d, char *message)
{
	printf("Error : %s\n", message);
	free_cub3d(cub3d);
	exit(EXIT_FAILURE);
}
