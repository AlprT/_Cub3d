/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:20:12 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:20:12 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void	check_args(t_cub3d *cub3d)
{
	char	*fn;

	fn = cub3d->data->fn;
	if (cub3d->data->ac != 2)
		err(cub3d, "argument requiretment not met.");
	if (fn == NULL || *fn == '\0')
		err(cub3d, "argument content is empty.");
	if (ft_strcmp(fn + ft_strlen(fn) - 4, ".cub") != 0)
		err(cub3d, "argumemt must be a .cub file.");
}
