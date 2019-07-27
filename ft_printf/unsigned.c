/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:14:37 by cdubuque          #+#    #+#             */
/*   Updated: 2019/07/26 16:49:50 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

size_t		ft_colvo_uns(unsigned long long n, size_t col, size_t i)
{
	while (n / i > 0)
	{
		col++;
		n /= i;
	}
	return (col);
}

char		*ft_putt_uns(unsigned long long  n, char *s, size_t i, size_t m)
{
	size_t		b;
	size_t	h;
	
	b = 1;
	h = 0;
	while (n / b >= i)
		b *= i;
	while (n >= i)
	{
		if (n / b > 9)
			s[h++] = 64 + m + ((n / b) - 9);
		else
			s[h++] = (n / b) + '0';
		while (n % b < i && n >= i * i)
		{
			s[h++] = '0';
			b /= i;
			n = n / i + n %i;
		}
		n = n - (n / b) * b;
		b /= i;
	}
	s[h++] = n + '0';
	s[h] = '\0';
	return (s);
}

char			*ft_unsigned(unsigned long long n, size_t i, size_t m)
{
	char	*s;
	size_t		col;
	
	i = 0;
	col = 1;
	col = ft_colvo_uns(n, col, i);
	if (!(s = (char *)malloc(sizeof(char) * col + 1)))
		return (NULL);
	s = ft_putt_uns(n, s, i, m);
	return (s);
}
