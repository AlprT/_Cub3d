/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:40 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:40 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	get_img_color(t_mlx_img *img, int x, int y)
{
	return (*(size_t *)((img->addr
			+ (y * img->size_line) + (x * img->bits_per_pixel / 8))));
}

void	put_pixel_to_mlx_img(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > SCREEN_HEIGHT)
		return ;
	if (x < 0 || x > SCREEN_WIDTH)
		return ;
	if (img->addr == NULL)
		return ;
	dst = img->addr
		+ (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
