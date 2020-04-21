/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:48:11 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/21 18:22:35 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_s_justif(char *s, struct flags *flags, int freed)
{
		int ret;

		ret = ft_strlen(s);
		if (flags->precision != -1 && flags->precision < ret)
		{
				ft_putnstr(s, flags->precision);
				return (flags->precision);
		}
		ft_putstr(s);
		if (freed == 1)
			free(s);
		return (ret);
}

int		print_s_next(int precision, char *s, int champs)
{
		int i;
		int len;

		i = 0;
		len = ft_strlen(s);
		if (precision != -1 && precision < len)
		{
			while (precision++ < champs)
			{
					ft_putchar(' ');
					i++;
			}
		}
		else
		{
			while (len < champs--)
			{
					ft_putchar(' ');
					i++;
			}
		}
		return (i);
}

int		print_s(va_list args, struct flags *flags )
{
		char *s;
		int	champs;
		int	precision;
		int	ret;
		int 	i;
		int freed = 0;

		champs = flags->taille_champs;
		precision = flags->precision;
		s = va_arg(args, char*);
		if (!s)
		{
			freed = 1;
			s = ft_strdup("(null)");
		}
		if (flags->justif == 1)
			ret = print_s_justif(s, flags, freed);
		i = print_s_next(precision, s, champs);
		if (flags->justif == 0)
			return (print_s_justif(s, flags, freed) + i);
		return (ret + i);
}
