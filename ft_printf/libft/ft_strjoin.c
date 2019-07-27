/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:22:43 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/30 18:21:30 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	char		*ss;
	size_t		col1;
	size_t		col2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	col1 = ft_strlen(s1);
	col2 = ft_strlen(s2);
	if (!(s = (char *)malloc(sizeof(char) * (col1 + col2 + 1))))
		return (NULL);
	ss = s;
	while (col1--)
		*s++ = *s1++;
	while (col2--)
		*s++ = *s2++;
	*s = '\0';
	return (ss);
}
