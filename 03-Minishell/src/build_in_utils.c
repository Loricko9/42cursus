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
			k++;
	}
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
			new[j] = str;
		}
		j++;
	}
	new[j] = NULL;
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
	return (new);
}

int is_exported(char **tab, char *str)
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
			return (i);
		}
		free(temp);
		i++;
	}
	return(-1);
}