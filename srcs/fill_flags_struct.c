/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:07:53 by ophelieba         #+#    #+#             */
/*   Updated: 2020/04/26 15:17:15 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	fill_flags_struct_next(t_flags *flags, char *fmt, va_list args, int i)
{
	if (fmt[i] == '.')
	{
		flags->precision = 0;
		if (fmt[i + 1] >= '0' && fmt[i + 1] <= '9')
			flags->precision = ft_atoi(&fmt[i + 1]);
		if (fmt[i + 1] == '*')
			flags->precision = va_arg(args, unsigned int);
		if (flags->precision < 0)
			flags->precision = -1;
	}
	if (fmt[i] == '0' && (fmt[i - 1] < '0' || fmt[i - 1] > '9'))
		flags->zero = 1;
	if (fmt[i] == '-')
		flags->justif = 1;
	return (0);
}

int	fill_flags_struct(t_flags *flags, char *fmt, va_list args)
{
	int i;

	i = 0;
	if ((fmt[i - 1] == '%' || fmt[i - 1] == '-')
		&& fmt[i] >= '0' && fmt[i] <= '9')
		flags->taille_champs = ft_atoi(&fmt[i]);
	if (fmt[i] == '*' && (fmt[i - 1] != '.'))
	{
		flags->taille_champs = va_arg(args, unsigned int);
		if (flags->taille_champs < 0)
		{
			flags->taille_champs = flags->taille_champs * -1;
			flags->justif = 1;
		}
	}
	fill_flags_struct_next(flags, fmt, args, i);
	return (0);
}
