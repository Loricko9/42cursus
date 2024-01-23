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
			free(tab[k++]);
	}
	free(tab);
	new[j++] = NULL;
	return (new);
}
