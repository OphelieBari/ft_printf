/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:44:28 by ophelieba         #+#    #+#             */
/*   Updated: 2020/03/10 15:06:59 by ophelieba        ###   ########.fr       */
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
int	ft_putnstr(char *str, int len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	*ft_memset(void *b, int c, size_t len);
int	ft_atoi(const char *str);
char	*ft_itoa(int n);
int     putnbr_hexa(unsigned int x, int signal);

#endif
