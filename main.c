/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:25:10 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/25 21:55:00 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char	*s = "HELLO";

	//ft_printf("%034s\n", s);
	//printf("%034s\n", s);	
	//ft_printf("hNE MvFD%0*uvf%6sJw%-X", 7, -120359681, NULL, 1695073651);
	//printf("hNE MvFD%0*uvf%6sJw%-X", 7, -120359681, NULL, 1695073651);	
	//printf("hey%s\n", 234);	
	//printf(" 1 lctickcL6%.2s%*cpiCXeWghOq%-.*ia", "coTqfEQk2TkhIC kFn8nOoqswB9XEtxvKO447v3EEQ GynQ6", -9, '\0', -6, 0);
	//ft_printf(" 2 lctickcL6%.2s%*cpiCXeWghOq%-.*ia", "coTqfEQk2TkhIC kFn8nOoqswB9XEtxvKO447v3EEQ GynQ6", -9, '\0', -6, 0);
	//ft_printf("hey%s\n", 234);
	//printf("%X\n", ft_printf("%X\n", 0));
	//printf("%X\n", printf("%X\n", 0));
	//printf("%d\n", ft_printf("hello, %s.", "gavin"));
	//printf("%d\n", printf("hello, %s.", "gavin"));	
	//printf("%d\n", ft_printf("%-32s", "abc"));
	//printf("%d\n", printf("%-32s", "abc"));	
	//ft_printf("%4s\n", s);
	//printf("%4s\n", s);
	//ft_printf("%-.*s\n", 5, s);
	//printf("%-.*s\n", 5, s);
	//ft_printf("%10s\n", s);
	//printf("%10s\n", s);
	//ft_printf("%1s\n", s);
	//printf("%1s\n", s);
	//ft_printf("%54s\n", s);
	//printf("%54s\n\n", s);
	ft_printf("ft : %-5.d\n", 0);
	printf("pt : %-5.d", 0);
	ft_printf("ft_printf : %x\n%x\n", -2147483647, 2147483647);
	printf("ft_printf : %x\n%x\n", -2147483647, 2147483647);
	return (0);
}
