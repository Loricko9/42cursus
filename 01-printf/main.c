#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_printf("salut\n"));
	printf("%d", printf("salut\n"));
}