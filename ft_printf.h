/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:44:28 by ophelieba         #+#    #+#             */
/*   Updated: 2020/03/04 16:58:50 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>    // a retirer à la fin
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *, ...);
int	ft_putnstr(char *str, int len);
int ft_putstr(char *str);
char*ft_strchr(const char *s, int c);
int ft_strchr_mod(const char *s, int c);
char	*ft_strdup(const char *s1);
int	ft_strlen(const char *s);

#endif
