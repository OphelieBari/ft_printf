/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:44:28 by ophelieba         #+#    #+#             */
/*   Updated: 2020/04/26 15:20:26 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int	precision;
	int	precision_na;
	int	justif;
	int	zero;
	int	taille_champs;
}				t_flags;

int				ft_printf(const char *fmt, ...);
int				ft_putnstr_mod(char *str);
int				ft_putstr(char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *s);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			*ft_memset(void *b, int c, size_t len);
int				ft_atoi(const char *str);
char			*ft_itoa(long long n);
int				print_d(va_list args, t_flags *flags);
int				print_s(va_list args, t_flags *flags);
int				print_u(va_list args, t_flags *flags);
int				print_x(va_list args, t_flags *flags, int signal);
int				print_c(va_list args, t_flags *flags);
int				print_p(va_list args, t_flags *flags);
int				print_pourcent(t_flags *flags);
int				fill_flags_struct(t_flags *flags, char *fmt, va_list args);
int				ft_putnstr(char *str, int len);

#endif
