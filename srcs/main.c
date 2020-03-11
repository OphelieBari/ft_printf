/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:25:10 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 16:38:57 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char	*s;
	unsigned int j;

	j = 5648;
	//ft_printf("%50.4s.\n", "Bonjour");
	ft_printf("%d\n", j);
	printf("%d\n", j);			
	ft_printf("%-25d\n", j);
	printf("%-25d\n", j);
	ft_printf("%04d\n", j);
	printf("%04d\n", j);
	ft_printf("%-.*d\n", 5, j);
	printf("%-.*d\n", 5, j);			
	ft_printf("%010d\n", j);
	printf("%010d\n", j);
	ft_printf("%01d\n", j);
	printf("%01d\n", j);
	ft_printf("%54d\n", j);
	printf("%54d\n\n", j);
	ft_printf("%10s\n", "hey");
	printf("%10s", "hey");
	return (0);
}
