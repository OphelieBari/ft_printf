#include <stdio.h>
#include "./libftprintf.h"

int main(void)
{
	int i;

	i = 1;
	char *s = malloc(6);
	printf("	---- Return = %d ----", ft_printf("hey%chey",'a'));
	printf("	---- Return = %d ----", printf("hey%chey",'a'));	
	return (0);
}
	//system("leaks a.out")}
