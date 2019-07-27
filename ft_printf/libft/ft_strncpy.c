/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:35:49 by cdubuque          #+#    #+#             */
/*   Updated: 2019/03/28 15:53:16 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s2[i] == '\0')
		{
			while (i < n)
				s1[i++] = '\0';
		}
		else
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (s1);
}