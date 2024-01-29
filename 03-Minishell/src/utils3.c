/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:17:54 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/13 17:17:54 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_check_redir(int *trig, int i, char *line)
{
	char	c;
	
	if (line[i] == '>' || line[i] == '<')
	{
		c = line[i];
		if (line[++i] == c)
			i++;
		if (line[i] == c)
		{
			*trig = 2;
			return ;
		}
		while (line[i] != '>' && line[i] != '<')
		{
			if (line[i] != ' ')
				return ;
			i++;
		}
		*trig = 2;
	}
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
