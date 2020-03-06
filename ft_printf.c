/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:03:07 by ophelieba         #+#    #+#             */
/*   Updated: 2020/03/06 17:55:06 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(va_list args)
{
	char *s;
	
	s = va_arg(args, char *);
	ft_putstr(s);
	return (0);
}

int		print_d(va_list args)
{
	int	i;
	
	i = va_arg(args, int);
	ft_putnbr(i);
	return (0);
}

int		print_c(va_list args)
{
	int c;
	
	c = va_arg(args, int);
	ft_putchar(c);
	return (0);
}

int 	check_args_flags(va_list args, char *fmt) //découper fmt
{
		int i;
		//t_stock_flags	*flags;

		i = 0;
		while (fmt[i] != '\0' && (ft_strchr("cspdiuxX%", fmt[i]) == 0))
		{
			//remplir la structure de flags -0.* + taille de champs
			i++;
		}
		if (!fmt[i])
			return (0);
		i++;
		if (fmt[i] == 'c')
			print_c(args); //il faudra rajouter la structure
		if (fmt[i] == 's')
			print_s(args);
		//if (fmt[i] == 'p')
		//	print_p(args);
		if (fmt[i] == 'd' || fmt[i] == 'i')
			print_d(args);
		//if (fmt[i] == 'u')
		//	print_u(args);
		//if (fmt[i] == 'x')
		//	print_x(args);
		//if (fmt[i] == 'X')
		//	print_X(args);
		if (fmt[i] == '%')
			ft_putchar('%');// il va probablement falloir creer une nouvelle fonction de dispatch
		return (i + 1);
}

int		check_for_param(va_list args, char *fmt)
{
	int ret;
	char*ptr;

	ret = 1;
	while (ft_strchr(fmt, '%') && ret != 0)
	{
		ptr = ft_strdup(ft_strchr(fmt, '%'));
		ft_putnstr_mod(fmt);
		ret = check_args_flags(args, ptr);
		free(fmt);
		ptr = ptr + ret;
		fmt = ft_strdup(ptr);
		//trouver l'endroit ou free ptr
	}
	ft_putstr(ptr);
	return (ret);
}

int		ft_printf(const char *fmt, ...) //verifier qu'on peut bien mettre le nom
{
	va_list	args;
	int	ret;
	char *new_fmt;
	
	ret = 0;
	new_fmt = ft_strdup(fmt);
	if (!fmt)
		return (ret);
	va_start(args, fmt);
	ret = check_for_param(args, new_fmt);
	va_end(args);
	return (ret);
}
