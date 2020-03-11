/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:03:07 by ophelieba         #+#    #+#             */
/*   Updated: 2020/03/10 22:23:04 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(va_list args, struct flags *flags )
{
	char *s;
	
	s = va_arg(args, char *);
	if (flags->justif == 1)
	{
		if (flags->precision != 0 && flags->precision < ft_strlen(s))
			ft_putnstr(s, flags->precision);
		else
			ft_putstr(s);
	}
	if (flags->precision != 0 && flags->precision < ft_strlen(s))
		while (flags->precision++ < flags->taille_champs)
			ft_putchar(' ');
	else
		while (ft_strlen(s) < flags->taille_champs)
			ft_putchar(' ');
	if (flags->justif == 0)
	{
		if (flags->precision != 0 && flags->precision < ft_strlen(s))
			ft_putnstr(s, flags->precision);
		else
			ft_putstr(s);
	}
	return (0);
}

int		print_d(va_list args, struct flags *flags)
{
	int	i;
	int	len;
	
	i = va_arg(args, int);
	len = ft_strlen(ft_itoa(i)); //il y a pas un malloc ici ??
	//faire de ci-dessous une fonction qui servira aussi pour le u !!
	if (flags->justif == 1) 
	{
		if (i < 0)
		{
			len--;
			i = i * -1;
			ft_putchar('-');
		}
		if (flags->precision > len)
			while (flags->precision > len)
			{
				len++;
				ft_putchar('0');
			}
		ft_putnbr(i);
		len++;
		while (flags->taille_champs > len)
		{
			len++;
			ft_putchar(' ');
		}
	}
	else
	{	
		while (flags->taille_champs > flags->precision + 1) //pb ici
		{
			flags->taille_champs--;
			if (flags->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		if (i < 0)
		{
			len--;
			i = i * -1;
			ft_putchar('-');
		}
		while (len++ < flags->precision)
			ft_putchar('0');
		ft_putnbr(i);
	}
	return (0);
}

int	print_x(va_list args, struct flags *flags, int signal)
{
	unsigned int x;

	x = (unsigned int)(va_arg(args, int));
	putnbr_hexa(x, signal);
	return (0);
	//reste à gerer les flags
}

int		print_c(va_list args, struct flags *flags)
{
	int c;
	
	c = va_arg(args, int);
	if (flags->justif == 1)
		ft_putchar(c);
	while (1 < flags->taille_champs)
	{
		ft_putchar(' ');
		flags->taille_champs--;
	}
	if (flags->justif == 0)
		ft_putchar(c);
	return (0);
}

int	print_u(va_list args)
{
	unsigned int u;

	u = va_arg(args, unsigned int);
	ft_putnbr(u);
	return (0);
}

int	fill_flags_struct(struct flags *flags, char *fmt, va_list args)
{
	int i;

	i = 0;
	
	if ((fmt[i - 1] == '%' || fmt[i - 1] == '-') && fmt[i] >= '0' && fmt[i] <= '9')
		flags->taille_champs = ft_atoi(&fmt[i]);
	if (fmt[i] == '.' )
	{
		if (fmt[i + 1] >= '0' && fmt[i + 1] <= '9')
			flags->precision = ft_atoi(&fmt[i + 1]); 
		if (fmt[i + 1] == '*')
			flags->precision = va_arg(args, int);
	}
	if (fmt[i] == '0' && (fmt[i - 1] < '0'
		|| fmt[i - 1] > '9') && (fmt[i + 1] < '0' || fmt[i + 1] > '9'))
		flags->zero = 1;
	if (fmt[i] == '-')
		flags->justif = 1;
	return (0);
}

int 	check_args_flags(va_list args, char *fmt)
{
		int i;
		struct flags	flags;

		i = 1;
		//rajouter le parsing
		ft_memset(&flags, 0, sizeof(struct flags));
		while (fmt[i] != '\0' && (ft_strchr("cspdiuxX%", fmt[i]) == 0))
		{
			fill_flags_struct(&flags, &fmt[i], args);
			i++;
		}
		if (!fmt[i])
			return (0);
		if (fmt[i] == 'c')
			print_c(args, &flags);
		if (fmt[i] == 's')
			print_s(args, &flags);
		//if (fmt[i] == 'p')
		//	print_p(args);
		if (fmt[i] == 'd' || fmt[i] == 'i')
			print_d(args, &flags);
		if (fmt[i] == 'u')
			print_u(args);
		if (fmt[i] == 'x')
			print_x(args, &flags, 0);
		if (fmt[i] == 'X')
			print_x(args, &flags, 1);
		if (fmt[i] == '%')
			ft_putchar('%');
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
