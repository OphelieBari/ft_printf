/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:46:38 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/21 19:32:06 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_d_justif(int i, struct flags *flags, int len)
{
		int ret;
		int len2;

		len2 = len;
		ret = 0;
		if (i < 0)
		{
				len2--;
				i = i * -1;
				ft_putchar('-');
				flags->taille_champs--;
		}
		if (flags->precision != -1 && flags->precision > len2)
		{
				while (flags->precision > len2)
				{
						len2++;
						ft_putchar('0');
						ret++;
				}
		}
		if (flags->precision != 0)
			ft_putnbr(i);
		while (flags->taille_champs > len2)
		{
				len2++;
				ft_putchar(' ');
				ret++;
		}
		if (flags->precision == 0)
		{
			if (ret < flags->taille_champs)
				ft_putchar(' ');
			return (flags->taille_champs);
		}
		return(ret + len);
}

int		print_d_nonjustif(int i, struct flags *flags, int len)
{
		int ret;
		int neg;
		int precision;
		int precision2;
		int champs;

		precision = flags->precision;
		precision2 = precision;
		champs = flags->taille_champs;
		ret = 0;
		neg = 0;	
		if (i < 0)
		{
				len--;
				i = i * -1;
				ret++;
				neg = 1;
				flags->taille_champs--;
		}
		if (flags->precision <= len)
			flags->precision = 0;
		if (neg == 1 && ((flags->zero == 1 && precision == -1 && champs > len) || (precision > champs) || (flags->precision == 0 && champs <= len)))
			ft_putchar('-');
		while ((flags->taille_champs > flags->precision && flags->precision > 0) || (flags->taille_champs > len && flags->precision == 0))
		{
				if (flags->zero == 1 && precision == -1)
						ft_putchar('0');
				else
						ft_putchar(' ');
				ret++;
				flags->taille_champs--;
		}
		if (neg == 1 && ((champs > precision && precision != -1 && flags->zero == 0) || (champs > len && flags->precision == 0 && flags->zero == 0) || (flags->zero == 1 && champs > precision && flags->precision > 0) || (precision >= 0 && precision < len && champs > len)))
			ft_putchar('-');
		while (len < precision--)
		{
				ft_putchar('0');
				ret++;
		}
		if (precision2 != 0)
		{
			ft_putnbr(i);
			return (ret + len);
		}
		if (ret < champs)
			ft_putchar(' '); 
		return (champs);
}

int		print_d(va_list args, struct flags *flags)
{
		int	i;
		int	len;

		i = va_arg(args, int);
		len = ft_strlen(ft_itoa(i)); //il y a pas un malloc ici ??
		if (flags->justif == 1)
				return(print_d_justif(i, flags, len));
		else
				return(print_d_nonjustif(i, flags, len));
}
