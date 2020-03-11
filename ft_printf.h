/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:44:28 by ophelieba         #+#    #+#             */
/*   Updated: 2020/03/11 19:19:03 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>    // a retirer à la fin
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct flags {
	int precision;
	int precision_na;
	int justif;
	int zero;
	int taille_champs;
} flags;

int		ft_printf(const char *, ...);
int		ft_putnstr_mod(char *str);
int 	ft_putstr(char *str);
int		ft_putnstr(char *str, int len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
int		print_d(va_list args, struct flags *flags);
int		print_s(va_list args, struct flags *flags );
int		print_u(va_list args, struct flags *flags);
int		print_x(va_list args, struct flags *flags, int signal);
int		print_c(va_list args, struct flags *flags);
int		print_p(va_list args, struct flags *flags);

#endif
