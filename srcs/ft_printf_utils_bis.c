/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:32:10 by ophelieba         #+#    #+#             */
/*   Updated: 2020/04/26 15:17:46 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int		ft_putnstr(char *str, int len)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && i < len)
		write(1, &str[i++], 1);
	return (0);
}

int		ft_putnstr_mod(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '%')
		write(1, &str[i++], 1);
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str == (char)c)
		return (str);
	return (0);
}
