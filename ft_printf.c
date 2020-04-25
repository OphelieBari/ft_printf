/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:03:07 by ophelieba         #+#    #+#             */
/*   Updated: 2020/04/25 23:08:51 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_flags_struct(struct flags *flags, char *fmt, va_list args)
{
	int i;

	i = 0;
	if ((fmt[i - 1] == '%' || fmt[i - 1] == '-') && fmt[i] >= '0' && fmt[i] <= '9')
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

int	dispatch(va_list args, char *fmt, struct flags *flags, int i)
{
	if (fmt[i] == 'c')
		return (print_c(args, flags));
	if (fmt[i] == 's')
		return (print_s(args, flags));
	if (fmt[i] == 'p')
		return (print_p(args, flags));
	if (fmt[i] == 'd' || fmt[i] == 'i')
		return (print_d(args, flags));
	if (fmt[i] == 'u')
		return (print_u(args, flags));
	if (fmt[i] == 'x')
		return (print_x(args, flags, 0));
	if (fmt[i] == 'X')
		return (print_x(args, flags, 1));
	if (fmt[i] == '%')
		return (print_pourcent(flags));
	return (0);
}

int	check_args_flags(va_list args, char *fmt, struct flags *flags)
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

int	check_for_param(va_list args, char *fmt)
{
	int		ret;
	char		*ptr;
	int		ret2;
	int		ret3;
	struct	flags	flags;
	char		*ptr2;

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
		ret2 = ret2 + ft_strlen(fmt);
		ft_putstr(fmt);
		free(fmt);
	}
	return (ret2 + ret3);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int		ret;
	char		*new_fmt;

	ret = 0;
	if (!fmt)
		return (ret);
	new_fmt = ft_strdup(fmt);
	va_start(args, fmt);
	ret = check_for_param(args, new_fmt);
	va_end(args);
	return (ret);
}
