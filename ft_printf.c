/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:03:07 by ophelieba         #+#    #+#             */
/*   Updated: 2020/04/21 19:23:10 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_flags_struct(struct flags *flags, char *fmt, va_list args)
{
		int i;

		i = 0;

		if ((fmt[i - 1] == '%' || fmt[i - 1] == '-') && fmt[i] >= '0' && fmt[i] <= '9')
				flags->taille_champs = ft_atoi(&fmt[i]);
		if (fmt[i] == '*')
			flags->precision = va_arg(args, int);
		if (fmt[i] == '.')
		{
				flags->precision = 0;
				if (fmt[i + 1] >= '0' && fmt[i + 1] <= '9')
						flags->precision = ft_atoi(&fmt[i + 1]); 
		}
		if (fmt[i] == '0' && (fmt[i - 1] < '0' || fmt[i - 1] > '9'))
				flags->zero = 1;
		if (fmt[i] == '-')
				flags->justif = 1;
		return (0);
}

int		dispatch(va_list args, char *fmt, struct flags *flags, int i)
{
		if (fmt[i] == 'c')
			print_c(args, flags);
		if (fmt[i] == 's')
			return(print_s(args, flags));
		if (fmt[i] == 'p')
			print_p(args, flags);
		if (fmt[i] == 'd' || fmt[i] == 'i')
			return(print_d(args, flags));
		if (fmt[i] == 'u')
			print_u(args, flags);
		if (fmt[i] == 'x')
			print_x(args, flags, 0);
		if (fmt[i] == 'X')
			print_x(args, flags, 1);
		if (fmt[i] == '%')
			ft_putchar('%');
		return (0);
}

int 	check_args_flags(va_list args, char *fmt, struct flags *flags)
{
		int i;

		i = 1;
		ft_memset(flags, 0, sizeof(struct flags));
		flags->precision = -1;
		while (fmt[i] != '\0' && (ft_strchr("cspdiuxX%", fmt[i]) == 0))
		{
				fill_flags_struct(flags, &fmt[i], args);
				i++;
		}
		if (!fmt[i])
			return (0);
		return (i + 1);
}

int		check_for_param(va_list args, char *fmt)
{
		int ret;
		char*ptr;
		int ret2;
		int ret3;
		struct flags	flags;
		char*ptr2;

		ret = 1;
		ret2 = 0;
		ret3 = 0;
		ptr = 0;
		while (ft_strchr(fmt, '%') && ret != 0)
		{
				ptr = ft_strdup(ft_strchr(fmt, '%'));
				ret3 = ret3 + ft_putnstr_mod(fmt);
				ret = check_args_flags(args, ptr, &flags);
				ret2 = ret2 + dispatch(args, ptr, &flags, ret - 1);
				free(fmt);
				ptr2 = ft_strdup(ptr + ret);
				fmt = ft_strdup(ptr2);
				free(ptr2);
				free(ptr);
		}
		if (fmt)
		{
			ft_putstr(fmt);
			free(fmt);
		}
		return (ret2 + ret3 + ft_strlen(fmt));
}

int		ft_printf(const char *fmt, ...) //verifier qu'on peut bien mettre le nom
{
		va_list	args;
		int	ret;
		char *new_fmt;

		ret = 0;
		if (!fmt)
			return (ret);
		new_fmt = ft_strdup(fmt);
		va_start(args, fmt);
		ret = check_for_param(args, new_fmt);
		va_end(args);
		return (ret);
}
