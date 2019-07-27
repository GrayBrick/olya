/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:55:11 by cdubuque          #+#    #+#             */
/*   Updated: 2019/07/26 17:38:54 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"
# include <stdio.h>

void		ft_string_width_and_accur(char *m, size_t i, char *s, size_t z)
{
	char	*w;
	char	*ac;
	size_t	j;
	
	j = 0;
	write(1, "Зашли в ft_width_and_accur\n", 33);
	ac = ft_strnew(ft_strlen(ft_strchr(m, '.') + 1) + 1);
	ft_strncpy(ac, ft_strchr(m, '.'), ft_strlen(ft_strchr(m, '.')) + 1);
	while (m[j] != '.')
		j++;
	if (!(w = (char *)malloc(sizeof(char) * (j + 1))))
		return ;
	ft_strncpy(w, m, j);
	w[j] = '\0';
	if (ft_modul(ac) < (int)i)
	{
		s = ft_string_accur(ac, i, s);
		i = ft_strlen(s);
	}
	if ((ft_atoi(ac) < ft_modul(w)) && ((int)i < ft_modul(w)))
	ft_null((size_t)ft_modul(m) - i, s, z);
	else
		ft_putstr(s);
}

char		*ft_string_accur(char *m, size_t i, char *s)
{
	int		id;

	write(1, "accur\n", 6);
/*	ft_putstr(m);*/
	id = ft_atoi(ft_strdup(m + 1));
	ft_putnbr(id);
	write(1, "\n", 1);
/*	ft_putnbr(i);*/
	if (id < (int)i)
		 s = ft_strsub(s, 0, id);
/*	ft_putstr(s);*/
	return(s);
}

void		ft_string(char *s, char *m)
{
	size_t	z;

	z = 0;
	write(1, "ft_string\n", 11);
/*	if (m[0] == '\0')
		ft_putstr(s);*/
	if(m[0] == '-')
	{
		while (m[0] == '-')
			m = ft_strdup(m + 1);
		z = 1;
		ft_putstr(m);
	}
	if (m[0] == '\0' || ((int)ft_strlen(s) >= ft_modul(m) && \
				ft_strchr(m, '.') == NULL))
		ft_putstr(s);
	else if ((ft_strchr(m, '.') == NULL) && (int)ft_strlen(s) < ft_modul(m))
		ft_null((size_t)ft_modul(m) - ft_strlen(s), s, z);
	else if (m[0] == '.')
		ft_string_accur(m, ft_strlen(s), s);
	else
		ft_string_width_and_accur(m, ft_strlen(s), s, z);
}

void		ft_char(char *s, char *m)
{
	size_t	z;
	
	z = 0;
	write(1, "ft_char\n", 11);
	/*	if (m[0] == '\0')
	 ft_putstr(s);*/
	if(m[0] == '-')
	{
		while (m[0] == '-')
			m = ft_strdup(m + 1);
		z = 1;
		ft_putstr(m);
	}
	if (m[0] == '\0')
		ft_putstr(s);
	else
		ft_null((size_t)ft_modul(m) - ft_strlen(s), s, z);
}

void		ft_string_and_char(char *mas, va_list ap, char c)
{
	char	*s;

	s = ft_strnew(BUFF_SIZE);
	if (c == 'c')
	{
		s = va_arg(ap, char *);
		ft_char(s, mas);
		return ;
	}
	if (c == 's')
	{
		s = va_arg(ap, char *);
		ft_string(s, mas);
		return ;
	}	
}
