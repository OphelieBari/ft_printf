/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:45:19 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/26 15:17:32 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		tests_atoi(int count, int i, const char *str)
{
	if (count > 1)
		return (0);
	if (count > 0 && i > 0 && ((str[i - 1] >= 9 && str[i - 1] <= 13) ||
				str[i - 1] == 32))
		return (0);
	else
		return (1);
}

int		fill_atoi(int i, const char *str)
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

int		ft_atoi(const char *str)
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

char	*fill_itoa(long long n, char *tab, int size)
{
	unsigned long long nbrneg;

	nbrneg = 0;
	if (n < 0)
	{
		nbrneg = (unsigned long long)n * -1;
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

char	*ft_itoa(long long n)
{
	int			size;
	long long	nbr;
	char		*tab;

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
