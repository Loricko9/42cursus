/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arpages@student.42.fr>              +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:15 by arthur            #+#    #+#             */
/*   Updated: 2024/01/23 16:18:16 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*creer un tableau de tableau(char **), sans la case a l'index i, 
et free le tableau originalt tab*/
char	**rm_index(char **tab, int i)
{
	int		j;
	int		k;
	char	**new;

	j = 0;
	k = 0;
	new = malloc(sizeof(char *) * ft_tablen(tab));
	while (k != ft_tablen(tab))
	{
		if (k != i)
			new[j++] = tab[k++];
		else
		{
			free(tab[k]);
			k++;
		}
	}
	free(tab);
	new[j] = NULL;
	return (new);
}

char	**mod_index(char **tab, int i, char *str)
{
	int		j;
	char	**new;

	j = 0;
	new = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (j < ft_tablen(tab))
	{
		if (j != i)
			new[j] = tab[j];
		else
		{
			free(tab[j]);
			new[j] = str;
		}
		j++;
	}
	new[j] = NULL;
	free(tab);
	return (new);
}

char	**add_index(char **tab, char *str)
{
	int		j;
	char	**new;

	j = 0;
	new = malloc(sizeof(char *) * (ft_tablen(tab) + 2));
	while (j != ft_tablen(tab))
	{
		new[j] = tab[j];
		j++;
	}
	new[j++] = str;
	new[j] = NULL;
	free(tab);
	return (new);
}

int	is_exported(char **tab, char *str, int type)
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[i] != NULL)
	{
		temp = get_var_name(tab[i]);
		if (ft_strcmp_shell(temp, str, 0) == 1)
		{
			free(temp);
			if (type == 1)
				free(str);
			return (i);
		}
		free(temp);
		i++;
	}
	if (type == 1)
		free(str);
	return (-1);
}

int	ft_check_export(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '=')
		return (print_error("minishell: export: '", str,
				"' not a valid identifier\n"), 1);
	while (str[i] != '=' && str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
			i++;
		else
			return (print_error("minishell: export: '", str,
					"' not a valid identifier\n"), 1);
	}
	return (0);
}
