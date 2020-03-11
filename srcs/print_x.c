/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:55:47 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 18:26:15 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	len_hexa(unsigned int x)
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

int		print_x_justif(int i, struct flags *flags, int len, int signal)
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
		putnbr_hexa(i, signal);
		len++;
		while (flags->taille_champs > len)
		{
				len++;
				ft_putchar(' ');
		}
		return(0);
}

int		print_x_nonjustif(int i, struct flags *flags, int len, int signal)
{
		while (flags->taille_champs > len)
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
		putnbr_hexa(i, signal);
		return (0);
}

int	print_x(va_list args, struct flags *flags, int signal)
{
		unsigned int x;
		int len;

		x = (unsigned int)(va_arg(args, int));
		len = len_hexa(x);
		if (flags->justif == 1)
				print_x_justif(x, flags, len, signal);
		else
				print_x_nonjustif(x, flags, len, signal);
		return (0);
}
