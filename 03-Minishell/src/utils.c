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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		if (i >= start)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_find_char_quote(const char *s1, const char c)
{
	int		i;
	char	trig;

	i = 0;
	trig = 0;
	while (s1[i] != '\0')
	{
		if (trig == 0 && (s1[i] == '"' || s1[i] == '\''))
			trig = s1[i];
		else if (trig > 0 && s1[i] == trig)
			trig = 0;
		if (s1[i] == c && trig == 0)
			return (1);
		i++;
	}
	return (0);
}
