/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:44:18 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/11 14:44:18 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_signal(void)
{
	if (signal(SIGINT, exec_signal) == SIG_ERR)
	{
		perror("minishell");
		exit(1);
	}
}

void	exec_signal(int signum)
{
	(void)signum;
	printf("\nminishell>");
}

int	ft_strcmp_shell(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] == ' ')
		j++;
	while (s1[j] != '\0' && s1[j] == s2[i] && s2[i] != '\0')
	{
		i++;
		j++;
	}
	if (s2[i] == '\0')
		return (1);
	return (0);
}

char	*ft_substr(char *str, int start)
{
	int		i;
	int		j;
	char	*new;

	i = start;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) - start) + 1);
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[j] = str[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}
