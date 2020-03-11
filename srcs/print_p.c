/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:13:24 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 19:28:45 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	len_hexa_p(long long x)
{
	int i;

	i = 0;
	while (x)
	{
		x = x / 16;
		i++;
	}
	return(i);
}

int	putnbr_hexa_p(long long x)
{
	int i;
	unsigned int nbr_final[12];
	char *basex = "0123456789abcdef";

	i = 0;
	
	ft_putstr("0x");
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

int		print_p_justif(long long i, struct flags *flags, int len)
{
		if (i < 0)
		{
				len--;
				i = i * -1;
				ft_putchar('-');
		}
		if (flags->precision > len)
				while (flags->precision > len)
				{
						len++;
						ft_putchar('0');
				}
		putnbr_hexa_p(i);
		len++;
		while (flags->taille_champs - 2 > len)
		{
				len++;
				ft_putchar(' ');
		}
		return(0);
}

int		print_p_nonjustif(long long i, struct flags *flags, int len)
{
		while (flags->taille_champs - 2> len)
		{
				flags->taille_champs--;
				if (flags->zero == 1)
						ft_putchar('0');
				else
						ft_putchar(' ');
		}
		if (i < 0)
		{
				len--;
				i = i * -1;
				ft_putchar('-');
		}
		while (len++ < flags->precision)
				ft_putchar('0');
		putnbr_hexa_p(i);
		return (0);
}

int	print_p(va_list args, struct flags *flags)
{
		long long p;
		int len;

		p = va_arg(args, long long);
		len = len_hexa_p(p);
		if (flags->justif == 1)
				print_p_justif(p, flags, len);
		else
				print_p_nonjustif(p, flags, len);
		return (0);
}
