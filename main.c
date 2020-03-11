/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:25:10 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/10 22:24:22 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char	*s;
	int i;
	unsigned int j;

	i = -2;
	j = (unsigned int)i;
	s = argv[2];
	//ft_printf("%50.4s.\n", "Bonjour");
	ft_printf("%x\n", &j);
	ft_printf("%ld\n", &j);
	printf("%p\n", &j);
	printf("%llx", &j);
	return (0);
}
