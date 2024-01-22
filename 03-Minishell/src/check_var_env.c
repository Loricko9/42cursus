/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:09:46 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/22 12:09:46 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_new_line(char *var, char *line, char *env, int *index)
{
	char	*new;
	int		i;
	int		j;
	int		l;

	new = malloc(sizeof(char) * (ft_strlen(line) - (ft_strlen(var) + 1) + ft_strlen(env) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	l = 0;
	while (line[i] != '$')
		new[j++] = line[i++];
	while (env[l] != '\0')
		new[j++] = env[l++];
	i = i + 1 + ft_strlen(var);
	while (line[i] != '\0')
		new[j++] = line[i++];
	new[j] = '\0';
	*index = *index + l;
	return (new);
}

char	*get_var(char *line)
{
	int		i;
	int		len;
	char	*var;

	i = 0;
	len = 0;
	while (line[len] != '\0' && (line[len] == '$' || (line[len] >= 'A'
			&& line[len] <= 'Z') || (line[len] >= 'a' && line[len] <= 'z') || (line[len] >= '0' && line[len] <= '9')))
		len++;
	var = malloc(sizeof(char) * (len + 1));
	if (!var)
		return (NULL);
	while (i < len)
	{
		var[i] = line[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char	*new_line(char *line, char **env, int *i)
{
	char	*new;
	char	*var;
	int		j;

	var = get_var(line + *i + 1);
	printf("var : %s\n", var);
	if (!var)
		return (NULL);
	j = 0;
	while (env[j] != NULL && ft_strcmp_shell(env[j], var, 2) == 0)
		j++;
	if (env[j] == NULL)
		new = create_new_line(var, line, "\0", i);
	else
		new = create_new_line(var, line, env[j] + ft_strlen(var) + 1, i);
	free(var);
	free(line);
	--*i;
	return (new);
}

char	*check_var(char *line, char **env)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (line[i] != '\0')
	{
		if (quote == 0 && line[i] == '\'')
			quote = 1;
		else if (quote == 1 && line[i] == '\'')
			quote = 0;
		if (line[i] == '$' && quote == 0)
			line = new_line(line, env, &i);
		if (!line)
			return (NULL);
		i++;
	}
	return (line);
}
