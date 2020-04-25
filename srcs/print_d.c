/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 13:34:12 by ophelieba         #+#    #+#             */
/*   Updated: 2020/04/25 22:15:51 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_d_justif(int d, struct flags *flags, int len, int dont)
{
	int ret;

	ret = 0;
	if (d < 0)
	{
		d = d * -1;
		ft_putchar('-');
	}
	while (flags->precision-- > len)
	{
		ft_putchar('0');
		ret++;
	}
	if (!dont)
		ft_putnbr(d);
	while (flags->taille_champs-- > 0)
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret + len);
}

int	print_d_njustif_next(struct flags *flags, int ret, int neg)
{
	if (flags->taille_champs >= 0 && flags->zero && neg)
		ft_putchar('-');
	while (flags->taille_champs > 0)
	{
		if (flags->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flags->taille_champs--;
		ret++;
	}
	return (ret);
}

int	print_d_njustif(int d, struct flags *flags, int len, int dont)
{
	int ret;
	int neg;

	ret = 0;
	neg = 0;
	if (d < 0)
	{
		d = d * -1;
		neg = 1;
		ret++;
	}
	ret = print_d_njustif_next(flags, ret, neg);
	if (neg && !flags->zero)
		ft_putchar('-');
	while (flags->precision-- > len)
	{
		ft_putchar('0');
		ret++;
	}
	if (!dont)
		ft_putnbr(d);
	return (ret - neg + len);
}

int	print_d(va_list args, struct flags *flags)
{
	int d;
	int len;
	int dont;

	dont = 0;
	d = va_arg(args, int);
	len = ft_strlen(ft_itoa(d));
	if (d == 0 && flags->precision == 0)
	{
		dont = 1;
		len--;
	}
	if (flags->precision > 0 && d < 0)
		flags->precision++;
	if (flags->taille_champs <= len || flags->taille_champs <= flags->precision)
		flags->taille_champs = 0;
	if (flags->precision >= 0 && flags->zero)
		flags->zero = 0;
	if (flags->precision > 0 && flags->precision <= len)
		flags->precision = 0;
	if (flags->precision > 0 && flags->taille_champs)
		flags->taille_champs = flags->taille_champs - flags->precision;
	if (flags->precision != -2 && flags->precision <= 0 && flags->taille_champs)
		flags->taille_champs = flags->taille_champs - len;
	if (flags->justif == 1)
		return (print_d_justif(d, flags, len, dont));
	if (flags->justif == 0)
		return (print_d_njustif(d, flags, len, dont));
	return (0);
}
