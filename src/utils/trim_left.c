/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:22 by atangil           #+#    #+#             */
/*   Updated: 2024/11/09 14:17:22 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

char	*trim_left(char *s1, char *set)
{
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	return (ft_strdup(s1));
}
