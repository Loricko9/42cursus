#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void	ft_trans(unsigned int i, char *s)
{
	(void)i;
	*s = 'i';
}

char	ft_trans2(unsigned int i, char s)
{
	(void)i;
	(void)s;
	return ('a');
}

int	main(int argc, char **argv)
{
	(void)argc;
	int	test = ft_atoi(argv[1]);
	
	printf("ft_atoi : %d\n\n", ft_atoi(argv[1]));
	if (test == 1)
		printf("ft_isalnum : %d\n\n", ft_isalnum(argv[2][0]));
	if (test == 2)
	{
		printf("ft_isalpha : %d\n\n", isalpha(argv[2][0]));
		printf("ft_isalpha : %d\n\n", ft_isalpha(argv[2][0]));
	}
	if (test == 3)
		printf("ft_isascii : %d\n\n", ft_isascii(argv[2][0]));
	if (test == 4)
		printf("ft_isdigit : %d\n\n", ft_isdigit(argv[2][0]));
	if (test == 5)
		printf("ft_isprint : %d\n\n", ft_isprint(argv[2][0]));
	
	printf("ft_itoa : %s\n\n", ft_itoa(test));
	
	char	*str = (char *)ft_calloc(ft_strlen(argv[2]) + 1, sizeof(char));
	size_t	i = 0;
	printf("ft_calloc : ");
	 
	printf("\n\n");

	printf("ft_memccpy : %s\n\n", (char *)ft_memccpy(str, argv[2], argv[1][0], ft_strlen(argv[2])));

	printf("ft_memchr : %s\n\n", (char *)ft_memchr(argv[2], argv[1][0], ft_strlen(argv[2])));

//	printf("ft_memcmp : %d\n\n", ft_memcmp(argv[2], argv[3], ft_strlen(argv[2])));

	char	*str2 = (char *)ft_calloc(ft_strlen(argv[2]) + 1, sizeof(char));
	printf("ft_memcpy : %s\n\n", (char *)ft_memcpy(str2, argv[2], ft_strlen(argv[2])));

	char	*str3 = (char *)ft_calloc(ft_strlen(argv[2]) + 1, sizeof(char));
	printf("ft_memmove : %s\n\n", (char *)ft_memmove(str3, argv[2], ft_strlen(argv[2])));

	char	*str4 = (char *)ft_calloc(ft_strlen(argv[2]) + 1, sizeof(char));
	printf("ft_memset : %s\n\n", (char *)ft_memset(str4, (int)argv[1][0], ft_strlen(argv[2])));

	int	FD = open("test.txt", O_WRONLY);

	ft_putchar_fd(argv[2][0], FD);
	ft_putchar_fd('\n', FD);
	ft_putendl_fd(argv[2], FD);
	ft_putnbr_fd(test, FD);
	ft_putchar_fd('\n', FD);
	ft_putstr_fd(argv[2], FD);

	i = 0;
	char **tab = ft_split(argv[2], argv[1][0]);
	printf("ft_split : \n");
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("\n");

	printf("ft_strchr : %s\n\n", ft_strchr(argv[2], argv[1][0]));

	printf("ft_strdup : %s\n\n", ft_strdup(argv[2]));

	printf("ft_strjoin : %s\n\n", ft_strjoin(argv[2], argv[3]));

	char *str6 = malloc(sizeof(char) * (ft_strlen(argv[2]) + ft_strlen(argv[3]) + 1));
	printf("%d\n", ft_strlen(str6));
	printf("ft_strlcpy : \n%d\n", ft_strlcpy(str6, argv[2], ft_strlen(argv[2]) + 1));
	printf("%s\n\n", str6);

	printf("ft_strlcat : \n%d\n", (int)ft_strlcat(str6, argv[3], (ft_strlen(argv[2]) + ft_strlen(argv[3]) + 1)));
	printf("%s\n\n", str6);

	printf("ft_strmapi : %s\n\n", ft_strmapi(argv[2], ft_trans2));

	printf("ft_strncmp : %d\n", ft_strncmp(argv[2], argv[3], test));
	printf("strncmp : %d\n\n", strncmp(argv[2], argv[3], test));

	printf("ft_strnstr : %s\n\n", ft_strnstr(argv[2], argv[3], ft_strlen(argv[2])));

	printf("ft_strrchr : %s\n\n", ft_strrchr(argv[2], argv[1][0]));

	char *str15 = ft_strtrim(argv[2], argv[1]);
	printf("ft_strtrim : %s\n\n", str15);

	printf("ft_substr : %s\n\n", ft_substr(argv[2], 2, ft_strlen(argv[2]) - 2));

	printf("ft_tolower : %c\n\n", (char)ft_tolower(argv[2][0]));

	printf("ft_toupper : %c\n\n", (char)ft_toupper(argv[2][0]));

	char *str5 = argv[2];
	ft_striteri(str5, ft_trans);
	printf("ft_striteri : %s\n\n", str5);
}
