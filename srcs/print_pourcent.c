/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pourcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:13:56 by ophelieba         #+#    #+#             */
/*   Updated: 2020/04/26 15:19:12 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	boucle_pourcent(t_flags *flags, int signal)
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

int	print_pourcent(t_flags *flags)
{
	int ret;

	ret = 0;
	if (flags->justif == 1)
	{
		ft_putchar('%');
		ret = boucle_pourcent(flags, 0) + 1;
	}
	if (flags->justif == 0)
	{
		if (flags->zero == 0)
		{
			ret = boucle_pourcent(flags, 0) + 1;
			ft_putchar('%');
		}
		else
		{
			ret = boucle_pourcent(flags, 1) + 1;
			ft_putchar('%');
		}
	}
	return (ret);
}
