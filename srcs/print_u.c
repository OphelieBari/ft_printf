/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:45:40 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 17:53:25 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_u_justif(unsigned int i, struct flags *flags, int len)
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

int		print_u_nonjustif(unsigned int i, struct flags *flags, int len)
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

int	print_u(va_list args, struct flags *flags)
{
		unsigned int u;
		int len;

		u = va_arg(args, unsigned int);
		len = ft_strlen(ft_itoa_u(u));
		if (flags->justif == 1)
				print_u_justif(u, flags, len);
		else
				print_u_nonjustif(u, flags, len);
		return (0);
}
