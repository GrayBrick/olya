/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:02:59 by cdubuque          #+#    #+#             */
/*   Updated: 2019/07/26 17:02:07 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_colvo(long long n, int col)
{
	while (n / 10 > 0)
	{
		col++;
		n /= 10;
	}
	return (col);
}

static void		ft_putt(long long n, char *s, int i)
{
	int		b;

	b = 1;
	while (n / b >= 10)
		b *= 10;
	while (n >= 10)
	{
		s[i++] = (n / b) + '0';
		while (n % b < 10 && n >= 100)
		{
			s[i++] = '0';
			b /= 10;
			n = n / 10 + n % 10;
		}
		n = n - (n / b) * b;
		b /= 10;
	}
	s[i++] = n + '0';
	s[i] = '\0';
}

static char		*ft_min(long long n)
{
	char	*s;
	char	c;
	int		i;
	int		b;

	c = '-';
	i = 0;
	b = 1;
	n = -(n + 1);
	if (!(s = (char *)malloc(sizeof(char) * 26)))
		return (NULL);
	s[i++] = c;
	while (n / b >= 10)
		b *= 10;
	while (n > 10)
	{
		s[i++] = (n / b) + '0';
		n = n - (n / b) * b;
		b /= 10;
	}
	s[i++] = 8 + '0';
	s[11] = '\0';
	return (s);
}

char			*ft_itoa(long long n)
{
	char	*s;
	char	c;
	int		col;
	int		i;

	i = 0;
	c = '0';
	col = 1;
	if (n > 9223372036854775807 || n < (-9223372036854775807 - 1))
		return (NULL);
	if (n == (-9223372036854775807 - 1))
		return (ft_min(n));
	if (n < 0)
	{
		col = 2;
		c = '-';
		n = -n;
	}
	col = ft_colvo(n, col);
	if (!(s = (char *)malloc(sizeof(char) * col + 1)))
		return (NULL);
	if (c == '-')
		s[i++] = c;
	ft_putt(n, s, i);
	return (s);
}
