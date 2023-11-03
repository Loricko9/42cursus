/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:01:16 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/01 11:01:16 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

int	check_char(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'E'
				&& map[j][i] != 'C' && map[j][i] != 'P')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_wall(char **map)
{
	int	i;
	int	j;
	int	end;

	end = ft_strlen(map[0]);
	j = 1;
	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	while (map[j + 1] != NULL)
	{
		if (ft_strlen(map[j]) != end || 
			(map[j][0] != '1' || map[j][end - 1] != '1'))
			return (1);
		j++;
	}
	if (check_wall2(map, j, end) == 1)
		return (1);
	return (0);
}

int	check_wall2(char **map, int j, int end)
{
	int	i;

	i = 0;
	if (ft_strlen(map[j]) != end)
		return (1);
	while (map[j][i] != '\0')
	{
		if (map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char **map)
{
	if (check_char(map) == 1 || check_char2(map) == 1 || 
		check_wall(map) == 1)
	{
		free_map(map);
		return (1);
	}
	else
		return (0);
}
