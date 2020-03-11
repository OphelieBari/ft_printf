/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:25:10 by obaribau          #+#    #+#             */
/*   Updated: 2020/03/11 19:31:40 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char	*s;
	unsigned int j;

	j = 48;
	printf("% 45.*");
	/*ft_printf("%034p\n", &j);
	printf("%034p\n", &j);			
	ft_printf("%-25p\n", &j);
	printf("%-25p\n", &j);
	ft_printf("%4p\n", &j);
	printf("%4p\n", &j);
	ft_printf("%-.*p\n", 5, &j);
	printf("%-.*p\n", 5, &j);			
	ft_printf("%10p\n", &j);
	printf("%10p\n", &j);
	ft_printf("%1p\n", &j);
	printf("%1p\n", &j);
	ft_printf("%54p\n", &j);
	printf("%54p\n\n", &j);*/
	return (0);
}
