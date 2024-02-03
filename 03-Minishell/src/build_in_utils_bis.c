/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_utils_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:22:46 by arthur            #+#    #+#             */
/*   Updated: 2024/01/24 16:07:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	name = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (line[i] && line[i] != '=')
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char	*get_var_value(char *line)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (line[i] == '=')
		i++;
	while (line[i + j] != '\0')
		j++;
	if (j == 0)
		return (NULL);
	value = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (line[i + j])
	{
		value[j] = line[i + j];
		j++;
	}
	value[j] = '\0';
	return (value);
}

int	is_var_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (line[i] != '=')
		return (2);
	if (line[i + 1] == '\0')
		return (1);
	return (0);
}

void	print_export(char **tab)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (tab[i] != NULL)
	{
		name = get_var_name(tab[i]);
		value = get_var_value(tab[i]);
		if (is_var_empty(tab[i]) == 2)
			printf("declare -x %s\n", name);
		else if (is_var_empty(tab[i]) == 0)
			printf("declare -x %s=\"%s\"\n", name, value);
		else
			printf("declare -x %s=\"\"\n", name);
		i++;
		free(name);
		free(value);
	}
}
