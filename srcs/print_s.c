/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:48:11 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 17:14:42 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_s_justif(char *s, struct flags *flags)
{
		if (flags->precision != 0 && flags->precision < ft_strlen(s))
				ft_putnstr(s, flags->precision);
		else
				ft_putstr(s);
		return (0);
}

int		print_s(va_list args, struct flags *flags )
{
		char *s;

		s = va_arg(args, char *);
		if (flags->justif == 1)
				print_s_justif(s, flags);
		if (flags->precision != 0 && flags->precision < ft_strlen(s))
				while (flags->precision++ < flags->taille_champs)
						ft_putchar(' ');
		else
				while (ft_strlen(s) < flags->taille_champs--)
						ft_putchar(' ');
		if (flags->justif == 0)
			print_s_justif(s, flags);
		return (0);
}
