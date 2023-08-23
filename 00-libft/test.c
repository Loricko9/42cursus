#include <libft.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n%s\n", ft_strlen(argv[1]), ft_strdup(argv[1]));
	int	tab[5];
	int tab2[5];
	size_t e = sizeof(tab) / sizeof(tab[0]);
	ft_memset(tab, 10, e * sizeof(tab[0]));
	memset(tab2, 10, e * sizeof(tab2[0]));
	size_t i = 0;
	while (i < e)
	{
		printf("%d ", tab[i]);
		i++;
	}
	i = 0;
	while (i < e)
	{
		printf("%d ", tab2[i]);
		i++;
	}
}