/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:45:19 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/10 22:23:26 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
		write(1, &c, 1);
}

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

int	ft_putnstr_mod(char *str)
{
		int i;

		i = 0;
		while (str[i] && str[i] != '%')
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

void	ft_putnbr(int nb)
{
	unsigned int n;
		
	n = (unsigned int)nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)b;
	while (len--)
		*str++ = (unsigned char)c;
	return (b);
}

int	tests_atoi(int count, int i, const char *str)
{
	if (count > 1)
		return (0);
	if (count > 0 && i > 0 && ((str[i - 1] >= 9 && str[i - 1] <= 13) ||
		str[i - 1] == 32))
		return (0);
	else
		return (1);
}

int	fill_atoi(int i, const char *str)
{
	int nb;

	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == '0')
		i++;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 ||
		str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '+' || str[i] == '-')
			count++;
		i++;
	}
	if (!tests_atoi(count, i, &str[0]))
		return (0);
	if (i > 0 && str[i - 1] == '-')
		sign = sign * -1;
	return (fill_atoi(i, &str[0]) * sign);
}

char	*fill_itoa(int n, char *tab, int size)
{
	unsigned int nbrneg;

	nbrneg = 0;
	if (n < 0)
	{
		nbrneg = (unsigned int)n * -1;
		tab[0] = '-';
		while (size > 0)
		{
			tab[size] = (nbrneg % 10) + 48;
			nbrneg = nbrneg / 10;
			size--;
		}
	}
	else
	{
		while (size >= 0)
		{
			tab[size] = (n % 10) + 48;
			n = n / 10;
			size--;
		}
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	int size;
	int nbr;
	char*tab;

	nbr = n;
	size = 1;
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	if (n < 0)
		size++;
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (0);
	tab[size--] = 0;
	return (fill_itoa(n, tab, size));
}

int	putnbr_hexa(unsigned int x, int signal)
{
	int i;
	unsigned int nbr_final[12];
       	char *baseX = "0123456789ABCDEF";
	char *basex = "0123456789abcdef";
	
	i = 0;
	        while (x)
	{
		nbr_final[i] = x % 16;
		 x = x / 16;
		i++;
	}
	while (--i >= 0)
	{
		if (signal == 1)
			ft_putchar(baseX[nbr_final[i]]);
		else
			ft_putchar(basex[nbr_final[i]]);
	}
	return (0);
}
