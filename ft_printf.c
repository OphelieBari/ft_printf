/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:03:07 by ophelieba         #+#    #+#             */
/*   Updated: 2020/03/04 17:53:35 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(va_list args)
{
	char *s;
	
	s = va_arg(args, char *);
	ft_putstr(s);
	//rajouter fmt en parametre et le couper
	return (0);
}

int 	check_args_flags(va_list args, char *fmt) //découper fmt
{
		int i;
		//t_stock_flags	*flags;

		i = 0;
		while (fmt[i] != '\0' && (ft_strchr_mod("cspdiuxX%", fmt[i]) == 0))
		{
			//remplir la structure de flags
			i++;
		}
		i++;
		//if (fmt[i] = 'c')
		//	print_c(&args, fmt); //il faudra rajouter la structure
		if (fmt[i] == 's')
		{
			print_s(args);
			return (0);
		}
		/*if (fmt[i] = 'p')
			print_p(&args, fmt);
		if (fmt[i] = 'd' || fmt[i] = 'i')
			print_d(&args, fmt);
		if (fmt[i] = 'u')
			print_u(&args, fmt);
		if (fmt[i] = 'x')
			print_x(&args, fmt);
		if (fmt[i] = 'X')
			print_X(&args, fmt);
		if (fmt[i] = '%')
			print_pourcent(&args, fmt);*/
		return (0);
}

int		check_for_param(va_list args, char *fmt)
{
	int ret;
	char*ptr;
	char *new_fmt;

	ret = 1;
	new_fmt = ft_strdup(fmt);
	while (ft_strchr(new_fmt, '%') && ret != 0)
	{
		ptr = ft_strchr(new_fmt, '%');
		ft_putnstr(new_fmt, (&ptr - &new_fmt + 2));
		ret = check_args_flags(args, ptr);
	}
	//ft_putstr(fmt);
	return (ret);
}

int		ft_printf(const char *fmt, ...) //verifier qu'on peut bien mettre le nom
{
	va_list	args;
	int	ret;
	
	//le fmt est caste
	ret = 0;
	if (!fmt)
		return (ret);
	va_start(args, fmt);
	ret = check_for_param(args, (char *)fmt);
	va_end(args);
	return (ret);
}
