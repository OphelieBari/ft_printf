/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:28:57 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 19:11:16 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	boucle_c(struct flags *flags, int signal)
{
	while (1 < flags->taille_champs)
	{
		if (signal == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		flags->taille_champs--;
	}
}

int		print_c(va_list args, struct flags *flags)
{
		int c;

		c = va_arg(args, int);
		if (flags->justif == 1)
		{
				ft_putchar(c);
				boucle_c(flags, 0);
		}
		if (flags->justif == 0)
		{ 
			if (flags->zero == 0)
			{
				boucle_c(flags, 0);
				ft_putchar(c);
			}
			else
			{
				boucle_c(flags, 1);
				ft_putchar(c);
			}
		}
		return (0);
}
