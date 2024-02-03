/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:17:54 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/03 19:05:56 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strcmp(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] != dest[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(long n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*str;

	nb = n;
	i = 2 + ft_count(nb);
	if (nb < 0)
		nb = nb * -1;
	str = malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	str[i - 1] = '\0';
	i = i - 2;
	while (nb / 10 != 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	str[i] = nb % 10 + 48;
	if (i == 1)
		str[0] = '-';
	return (str);
}

char	*print_start(void)
{
	char	pwd[1024];
	char	*temp;
	char	*result;

	getcwd(pwd, 1024);
	temp = ft_strjoin("\001\033[95m\002minishell>:\001\033[36m\002", pwd);
	result = ft_strjoin(temp, "\001\033[5;95m\002-> \001\033[0m\002");
	free(temp);
	return (result);
}
