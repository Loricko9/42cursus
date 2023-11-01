/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:34:03 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/01 11:34:03 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char_spe(char car, int *e, int *c, int *p)
{
	if (car == 'E')
		*e = *e + 1;
	else if (car == 'C')
		*c = *c + 1;
	else if (car == 'P')
		*p = *p + 1;
}

int	check_char2(char **map)
{
	int i;
	int j;
	int e;
	int p;
	int	c;

	j = -1;
	e = 0;
	p = 0;
	c = 0;
	while (map[++j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			check_char_spe(map[j][i], &e, &c, &p);
			i++;
		}
	}
	if (e != 1 || p != 1 || c < 1)
		return (1);
	return (0);
}

int	get_path(char **map, int j, int i, long long iter)
{
	if (map[j][i] == '1' || (map[j][i] == 'P' && iter > 0))
		return (1);
	if (map[j][i] == 'E')
		return (0);
	iter++;
	if (get_path(map , j + 1, i, iter) == 0)
		return (0);
	if (get_path(map , j, i + 1, iter) == 0)
		return (0);
	if (get_path(map , j - 1, i, iter) == 0)
		return (0);
	if (get_path(map , j, i - 1, iter) == 0)
		return (0);
	return (1);
}

int	check_path(char **map)
{
	int i;
	int j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'P')
				return (get_path(map, j, i, 0));
			i++;
		}
		j++;
	}
	return (1);
}

