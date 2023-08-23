#include <stdio.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);

int	main(void)
{
	char	buff[10];

	ft_bzero(buff, sizeof(buff));
	int	i = 0;
	while (i < 10)
	{
		printf("%d ", buff[i]);
		i++;
	}
}