#include <libft.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n%s\n", ft_strlen(argv[1]), ft_strdup(argv[1]));
}