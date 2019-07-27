/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:55:57 by cdubuque          #+#    #+#             */
/*   Updated: 2019/07/26 17:43:35 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"
# include <stdio.h>

int		ft_modul (char *mas)
{
	int		i;

	i = atoi(mas);
	if (i > 0)
		return (i);
	else
		return (-i);
}

void		ft_width_and_accur(char *m, size_t i, char *s, int ii)
{
	char	*w;
	char	*ac;
	size_t	j;

	j = 0;
/*	write(1, "Зашли в ft_width_and_accur\n", 33);*/
	ac = ft_strnew(ft_strlen(ft_strchr(m, '.') + 1) + 1);
	ft_strncpy(ac, ft_strchr(m, '.') + 1, ft_strlen(ft_strchr(m, '.') + 1) + 1);
	while (m[j] != '.')
		j++;
	if (!(w = (char *)malloc(sizeof(char) * (j + 1))))
		return ;
	ft_strncpy(w, m, j);
	w[j] = '\0';
	if (ft_modul(ac) > (int)i)
	{
		s = ft_only_accur(ac, i, s);
		i = ft_strlen(s);
	}
	if (ft_atoi(ac) <= ft_modul(w))
		ft_only_width(m, i, s, ii);
}

char		*ft_only_accur(char *mas, size_t i, char *s)
{
	char	*m;
	size_t	k;
	int		r;
	char	*res;

	k = 0;
	r = ft_modul(mas) - i;
/*	ft_putnbr(r);
	write(1, "\n", 1);
	ft_putnbr(i);
	write(1, "Зашли в ft_only_accur\n", 29);*/
	if (r > 0)
	{
		m = ft_strnew(r);
		while (r--)
			mas[k++] = '0';
		mas[k] = '\0';
		res = ft_strnew(i + ft_strlen(mas));
		res = ft_strjoin(mas, s);
	}
	else
	{
		res = ft_strnew(ft_strlen(s));
	}
/*	write (1, "\n", 2);*/
	return(res);
}

void		ft_null(size_t i, char *s, size_t z)
{
	char	*mas;
	size_t	k;

	k = 0;
	mas = ft_strnew(BUFF_SIZE);
	/*	write (1, "Зашли в ft_null\n", 23);
	 ft_putnbr(i);
	 write (1, "\n", 1);*/
	if (i > 0)
	{
		if (z == 2)
		{
			while (i--)
				mas[k++] = '0';
			mas[k] = '\0';
		/*	ft_putstr(mas);*/
			ft_putstr(ft_strjoin(mas, s));
		}
		else
		{
			while (i--)
				mas[k++] = ' ';
			mas[k] = '\0';
			if (z == 1)
				ft_putstr(ft_strjoin(s, mas));
			else
				ft_putstr(ft_strjoin(mas, s));
		}
	}
	else
		ft_putstr(s);
}

void		ft_znak(size_t i, char *s, size_t z, size_t ii)
{
	char	*mas;
	size_t	k;

	k = 0;
/*	write (1, "Зашли в ft_null\n", 23);
	ft_putnbr(i);
	write (1, "\n", 1);*/
	mas = ft_strnew(3);
/*	ft_putnbr((int)ft_strlen(mas));
	write (1, "\n", 1);*/
	if (ii == 1)
		mas[k++] = '+';
	else if (ii == 2 || ii == 3)
	{
		mas[k++] = '0';
		if (ii == 2)
			mas[k++] = 'X';
		else
			mas[k++] = 'x';
	}
	else if (ii == 4)
		mas[k++] = '0';
	mas[k] = '\0';
	if (ft_strlen(mas) > 0)
		s = ft_strjoin(mas, s);
	if (i - ft_strlen(mas) > 0)
		ft_null(i - ft_strlen(mas), s, z);
	else
		ft_null(0, s, z);
}

void		ft_only_width(char *mas, size_t i, char *s, size_t ii)
{
	size_t		k;
	size_t		z;
	
	k = 0;
	z = 0;
/*	write(1, "Зашли в ft_only_width\n", 28);
	ft_putnbr(i);*/
	if (mas[k] == '-')
	{
		while (mas[k] == '-')
			mas = ft_strdup(mas + 1);
	/*	ft_putendl(mas);*/
		z = 1;
	}
	if (mas[k++] == '0' && z == 0)
		z = 2;
	k = atoi(mas);
/*	ft_putnbr(k);
	write (1, "\n", 2);*/

	if (k <= i)
		ft_putstr(s);
	if (k > i)
		ft_znak(k - i, s, z, ii);		
}

void		ft_int(char *s, char *m, size_t h)
{
	size_t	j;
	
	j = 0;
	printf("Зашёл в ft_int\n");
/*	i = va_arg (ap, int);
	s = ft_itoa(i);*/
	printf("Поступившее число = %s\n", s);
	ft_putstr(m);
	write(1, "\n", 1);
/*	if (m[0] == '\0')
	:wq
	ft_putstr(s);
		ft_putnbr(h);*/
	if (h == 1)
		ft_putchar(32);
/*	write(1, "\n", 1);
	ft_putstr(m);
	write(1, "\n", 1);*/
	if (m[0] == '\0')
		ft_putstr(s);
/*	write(1, "here\n", 5);*/
	else if (ft_strchr(m, '.') == NULL)
	{
	/*	write(1, "i\n", 2);*/
		ft_only_width(m, ft_strlen(s), s, h);
	}
	else if (m[0] == '-' || m[0] == '0' || m[0] == '.')
	{
/*		write(1, "yy\n", 4);*/
		while (m[j] != '.')
		{
	/*		write(1, "yyy\n", 3);
			write(1, &m[j], 1);*/
			if (m[j++] != '0')
			{
	/*			write(1, "yyyy\n", 5);*/
				ft_width_and_accur(m, ft_strlen(s), s, h);
				return ;
			}
			ft_putstr(m);
		}
		m = ft_strdup(m + 1);
		ft_putstr(ft_only_accur(m, ft_strlen(s), s));
	}
	else
		ft_width_and_accur(m, ft_strlen(s), s, h);
}
