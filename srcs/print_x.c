/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:55:47 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/26 15:20:05 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	len_hexa(unsigned int x)
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

int	putnbr_hexa(unsigned int x, int signal)
{
	int				i;
	unsigned int	nbr_final[12];
	char			*basex_maj;
	char			*basex;

	i = 0;
	basex = "0123456789abcdef";
	basex_maj = "0123456789ABCDEF";
	if (x == 0)
		ft_putchar('0');
	while (x)
	{
		nbr_final[i] = x % 16;
		x = x / 16;
		i++;
	}
	while (--i >= 0)
	{
		if (signal == 1)
			ft_putchar(basex_maj[nbr_final[i]]);
		else
			ft_putchar(basex[nbr_final[i]]);
	}
	return (0);
}

int	print_x_just(unsigned int i, t_flags *flags, int len, int signal)
{
	int ret;

	ret = 0;
	if (flags->precision > len)
	{
		while (flags->precision > len)
		{
			len++;
			ft_putchar('0');
			ret++;
		}
	}
	if (signal != 3)
		putnbr_hexa(i, signal);
	len++;
	while (flags->taille_champs >= len)
	{
		len++;
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}

int	print_x_nonjustif(int i, t_flags *flags, int len, int signal)
{
	int ret;

	ret = 0;
	while ((flags->precision > len && flags->taille_champs > flags->precision
			&& signal != 3) || (flags->precision <= len
			&& flags->taille_champs > len && signal != 3)
			|| (signal == 3 && flags->taille_champs > 0))
	{
		flags->taille_champs--;
		if (flags->zero == 1 && flags->precision == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	while (len < flags->precision--)
	{
		ft_putchar('0');
		ret++;
	}
	if (signal != 3)
		putnbr_hexa(i, signal);
	return (ret);
}

int	print_x(va_list args, t_flags *flags, int signal)
{
	unsigned int	x;
	int				len;

	x = (va_arg(args, unsigned int));
	len = len_hexa(x);
	if (flags->precision == 0 && x == 0)
	{
		signal = 3;
		len--;
	}
	if (flags->justif == 1)
		return (print_x_just(x, flags, len, signal) + len);
	else
		return (print_x_nonjustif(x, flags, len, signal) + len);
	return (0);
}
