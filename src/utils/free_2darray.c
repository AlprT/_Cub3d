/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2darray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:49 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:49 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_2darray(char **ptr)
{
	int	i;

	if (ptr == NULL)
		return ;
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

