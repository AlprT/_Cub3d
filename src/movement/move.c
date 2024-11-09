/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:21 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:18:21 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub3d.h"

void	player_move_up(t_map *map, t_player *player)
{
	t_vector_double	new_pos;

	new_pos.y = player->pos.y + player->direction.y * MOVE_SPEED;
	new_pos.x = player->pos.x + player->direction.x * MOVE_SPEED;
	if (map->text[(int)new_pos.y] == NULL)
		return ;
	if (map->text[(int)new_pos.y][(int)new_pos.x] == '1')
		return ;
	player->pos.x += player->direction.x * MOVE_SPEED;
	player->pos.y += player->direction.y * MOVE_SPEED;
}

void	player_move_down(t_map *map, t_player *player)
{
	t_vector_double	new_pos;

	new_pos.y = player->pos.y - player->direction.y * MOVE_SPEED;
	new_pos.x = player->pos.x - player->direction.x * MOVE_SPEED;
	if (map->text[(int)new_pos.y] == NULL)
		return ;
	if (map->text[(int)new_pos.y][(int)new_pos.x] == '1')
		return ;
	player->pos.x -= player->direction.x * MOVE_SPEED;
	player->pos.y -= player->direction.y * MOVE_SPEED;
}

void	player_move_left(t_map *map, t_player *player)
{
	t_vector_double	new_pos;

	new_pos.y = player->pos.y - player->camera_plane.y * MOVE_SPEED;
	new_pos.x = player->pos.x - player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)new_pos.y] == NULL)
		return ;
	if (map->text[(int)new_pos.y][(int)new_pos.x] == '1')
		return ;
	player->pos.x -= player->camera_plane.x * MOVE_SPEED;
	player->pos.y -= player->camera_plane.y * MOVE_SPEED;
}

void	player_move_right(t_map *map, t_player *player)
{
	t_vector_double	new_pos;

	new_pos.y = player->pos.y + player->camera_plane.y * MOVE_SPEED;
	new_pos.x = player->pos.x + player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)new_pos.y] == NULL)
		return ;
	if (map->text[(int)new_pos.y][(int)new_pos.x] == '1')
		return ;
	player->pos.x += player->camera_plane.x * MOVE_SPEED;
	player->pos.y += player->camera_plane.y * MOVE_SPEED;
}
