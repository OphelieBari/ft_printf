/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:03:07 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/14 14:36:40 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...); //verifier qu'on peut bien mettre le nom
{
	va_list	args;
	int	ret;
	
	ret = 0;
	if (!fmt)
		return (ret);
	va_start(args, fmt);
	ret = check_for_param(&args, fmt);
	va_end(args);
	return (ret);
}

int	check_for_param(va_list *args, char *fmt)
{
	int ret;
	char*ptr;

	while (ft_strchr(fmt, "%") && ret != 0)
	{
		ptr = ft_strchr(&fmt, "%");
		ft_putstr_mod(fmt, fmt - ptr);
		ret = cut_fmt(&args, &fmt);
	}
	ft_putstr(fmt);
	return (ret);
}

int 	cut_fmt(char *args, char **fmt) //découper fmt
{
	
}
