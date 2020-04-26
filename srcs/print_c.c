/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:28:57 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/26 15:18:25 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	boucle_c(t_flags *flags, int signal)
{
	int ret;

	ret = 0;
	while (1 < flags->taille_champs)
	{
		if (signal == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		flags->taille_champs--;
		ret++;
	}
	return (ret);
}

int	print_c(va_list args, t_flags *flags)
{
	int c;
	int ret;

	ret = 0;
	c = va_arg(args, int);
	if (flags->justif == 1)
	{
		ft_putchar(c);
		ret = boucle_c(flags, 0) + 1;
	}
	if (flags->justif == 0)
	{
		if (flags->zero == 0)
		{
			ret = boucle_c(flags, 0) + 1;
			ft_putchar(c);
		}
		else
		{
			ret = boucle_c(flags, 1) + 1;
			ft_putchar(c);
		}
	}
	return (ret);
}
