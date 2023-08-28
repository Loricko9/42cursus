#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s %d\n", ft_strnstr(argv[1], argv[2], 13), ft_strncmp(argv[1], argv[2], 13));
	printf("%s %d\n", strstr(argv[1], argv[2]), strncmp(argv[1], argv[2], 13));
}