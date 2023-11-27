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
	int	i;
	int	j;
	int	e;
	int	p;
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

int	get_path(char **map, int jend, int iend, t_pos *pos)
{
	int		top;
	t_pos	cur;

	top = 1;
	while (top > 0)
	{
		top--;
		cur.j = pos[top].j;
		cur.i = pos[top].i;
		if (cur.j == jend && cur.i == iend)
			return (0);
		if (map[cur.j + 1][cur.i] != '1' && map[cur.j + 1][cur.i] != '2')
		{
			pos[top].j = cur.j + 1;
			pos[top].i = cur.i;
			map[cur.j + 1][cur.i] = '2';
			top++;
		}
		get_path2(map, pos, &top, cur);
	}
	return (1);
}

void	get_start(t_pos *pos, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'P')
			{
				pos[0].i = i;
				pos[0].j = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

int	check_path(char **map)
{
	t_pos	pos[STACK_SIZE];
	int		i;
	int		j;
	int		res;
	char	**map_copy;

	j = 0;
	get_start(pos, map);
	map_copy = dup_map(map);
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'E')
			{
				res = get_path(map_copy, j, i, pos);
				free_map(map_copy);
				return (res);
			}
			i++;
		}
		j++;
	}
	return (1);
}
