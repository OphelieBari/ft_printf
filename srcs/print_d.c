/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:46:38 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 16:47:58 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d_justif(int i, struct flags *flags, int len)
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
		ft_putnbr(i);
		len++;
		while (flags->taille_champs > len)
		{
				len++;
				ft_putchar(' ');
		}
		return(0);
}

int		print_d_nonjustif(int i, struct flags *flags, int len)
{
		while (flags->taille_champs > len) //pb ici
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
		ft_putnbr(i);
		return (0);
}

int		print_d(va_list args, struct flags *flags)
{
		int	i;
		int	len;

		i = va_arg(args, int);
		len = ft_strlen(ft_itoa(i)); //il y a pas un malloc ici ??
		if (flags->justif == 1)
				print_d_justif(i, flags, len);
		else
				print_d_nonjustif(i, flags, len);
		return (0);
}
