/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:19:05 by cdubuque          #+#    #+#             */
/*   Updated: 2018/12/15 19:00:37 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	if (!(c = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size + 1)
	{
		c[i] = '\0';
		i++;
	}
	return (c);
}
