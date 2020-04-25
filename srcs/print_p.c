/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:13:24 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/25 22:05:06 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	len_hexa_p(long long x)
{
	int i;

	i = 0;
	if (x == 0)
		i++;
	while (x)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

int	putnbr_hexa_p(long long x)
{
	int		i;
	long long	nbr_final[12];
	char		*basex = "0123456789abcdef";

	i = 0;
	if (x == 0)
		ft_putchar('0');
	while (x)
	{
		nbr_final[i] = x % 16;
		x = x / 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar(basex[nbr_final[i]]);
	return (0);
}

int	print_p_justif(long long i, struct flags *flags, int len)
{
	int ret;

	ret = 0;
	ft_putstr("0x");
	if (flags->precision > len)
	{
		while (flags->precision > len)
		{
			len++;
			ft_putchar('0');
			ret++;
		}
	}
	putnbr_hexa_p(i);
	len++;
	while (flags->taille_champs >= len)
	{
		len++;
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}

int	print_p_nonjustif(long long i, struct flags *flags, int len)
{
	int ret;

	ret = 0;
	while ((flags->precision > len && flags->taille_champs > flags->precision)
			|| (flags->precision < len && flags->taille_champs > len))
	{
		flags->taille_champs--;
		if (flags->zero == 1 && flags->precision == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	ft_putstr("0x");
	while (len < flags->precision--)
	{
		ft_putchar('0');
		ret++;
	}
	putnbr_hexa_p(i);
	return (ret);
}

int	print_p(va_list args, struct flags *flags)
{
	long long	x;
	int		len;

	x = (va_arg(args, long long));
	len = len_hexa_p(x) + 2;
	flags->precision = flags->precision + 2;
	if (flags->precision >= 0 && flags->precision < len)
		flags->precision = 0;
	if (flags->taille_champs <= len)
		flags->taille_champs = 0;
	if (flags->justif == 1)
		return (print_p_justif(x, flags, len) + len);
	else
		return (print_p_nonjustif(x, flags, len) + len);
	return (0);
}
