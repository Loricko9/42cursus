#include "libft.h"
#include <stdio.h>
#include "unistd.h"

int	main(int argc, char **argv)
{
	(void)argc;
	int	test = ft_atoi(argv[1]);
	
	printf("ft_atoi : %d\n\n", ft_atoi(argv[1]));
	if (test = 1)
		printf("ft_isalnum : %d\n\n", ft_isalnum(argv[2][0]));
	if (test = 2)
		printf("ft_isalpha : %d\n\n", ft_isalpha(argv[2][0]));
	if (test = 3)
		printf("ft_isascii : %d\n\n", ft_isascii(argv[2][0]));
	if (test = 4)
		printf("ft_isdigit : %d\n\n", ft_isdigit(argv[2][0]));
	if (test = 5)
		printf("ft_isprint : %d\n\n", ft_isprint(argv[2][0]));
	
	printf("ft_itoa : %s\n\n", ft_itoa(test));
	
	char	*str = (char *)ft_calloc(ft_strlen(argv[2]) + 1, sizeof(char));
	printf("ft_calloc : %s\n\n", str);

	printf("ft_memccpy : %s\n\n", ft_memccpy(str, argv[2], argv[1], ft_strlen(argv[2])));

	printf("ft_memchr : %s\n\n", ft_memchr(argv[1], test, ft_strlen(argv[1])));

	printf("ft_memcmp")

}
