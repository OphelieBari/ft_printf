/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:45:19 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/04 16:59:14 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int	ft_putnstr(char *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
		write(1, &str[i++], 1);
	return (0);
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

int	ft_strchr_mod(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str == (char)c)
		return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
