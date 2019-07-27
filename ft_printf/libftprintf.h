/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:52:28 by cdubuque          #+#    #+#             */
/*   Updated: 2019/07/26 22:50:31 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define BUFF_SIZE 545
# include "./libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>

void		width(char *mas, size_t i, char *s);
size_t		identifier(char *s, size_t i, va_list ap);
int			ft_printf(char *s, ...);
void		ft_int(char *s, char *m, size_t h);
void		ft_only_width(char *mas, size_t i, char *s, size_t ii);
void		ft_null(size_t i, char *s, size_t z);
char		*ft_only_accur(char *mas, size_t i, char *s);
void		ft_width_and_accur(char *m, size_t i, char *s, int ii);
void		ft_string(char *s, char *m);
int			ft_modul(char *mas);
void		ft_string_width_and_accur(char *m, size_t i, char *s, size_t z);
char		*ft_string_accur(char *m, size_t i, char *s);
void		ft_char(char *s, char *m);
void		ft_intint(char *m, va_list ap, size_t h, char *spez);
void		ft_uns(char *m, va_list ap, char c, char *spez);
void		ft_znak(size_t i, char *s, size_t z, size_t ii);
void		ft_string_and_char(char *mas, va_list ap, char c);
size_t		ft_colvo_uns(unsigned long long a, size_t col, size_t i);
char		*ft_putt_uns(unsigned long long  n, char *s, size_t i, size_t m);
char		*ft_unsigned(unsigned long long a, size_t i, size_t m);
#endif
