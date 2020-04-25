/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:55:47 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/25 23:01:40 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	int		i;
	unsigned int	nbr_final[12];
	char		*baseX = "0123456789ABCDEF";
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
	{
		if (signal == 1)
			ft_putchar(baseX[nbr_final[i]]);
		else
			ft_putchar(basex[nbr_final[i]]);
	}
	return (0);
}

int	print_x_justif(unsigned int i, struct flags *flags, int len, int signal, int dont)
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
	if (!dont)
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

int	print_x_nonjustif(int i, struct flags *flags, int len, int signal, int dont)
{
	int ret;

	ret = 0;
	while ((flags->precision > len && flags->taille_champs > flags->precision && !dont)
			|| (flags->precision <= len && flags->taille_champs > len && !dont) || (dont && flags->taille_champs > 0))
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
	if (!dont)
		putnbr_hexa(i, signal);
	return (ret);
}

int	print_x(va_list args, struct flags *flags, int signal)
{
	unsigned int	x;
	int		len;
	int 	dont;

	dont = 0;
	x = (va_arg(args, unsigned int));
	len = len_hexa(x);
	if (flags->precision == 0 && x == 0)
	{
		dont = 1;
		len--;
	}
	if (flags->justif == 1)
		return (print_x_justif(x, flags, len, signal, dont) + len);
	else
		return (print_x_nonjustif(x, flags, len, signal, dont) + len);
	return (0);
}
