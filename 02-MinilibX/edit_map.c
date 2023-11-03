/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:37:10 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/02 11:37:10 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_garage(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'E')
			{
				data->map[j][i] = 'O';
				return ;
			}
			i++;
		}
		j++;
	}
}

void	ft_move(t_data *data, char c)
{
	if (data->map[data->y][data->x] != c)
		data->map[data->y][data->x] = c;
	else if (c == 'D' && data->map[data->y + 1][data->x] != '1' && 
				data->map[data->y + 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'C' ||
				data->map[data->y + 1][data->x] == 'O')
			data->collect = data->collect - 1;
		data->map[data->y][data->x] = '0';
		data->y = data->y + 1;
		data->map[data->y][data->x] = 'D';
		data->counter++;
	}
	else if (c == 'P')
		ft_move3(data, c);
	else if (c == 'U' || c == 'L') 
		ft_move2(data, c);
}

void	ft_move2(t_data *data, char c)
{
	if (c == 'U' && data->map[data->y - 1][data->x] != '1' && 
				data->map[data->y - 1][data->x] != 'E')
	{
		if (data->map[data->y - 1][data->x] == 'C' ||
				data->map[data->y - 1][data->x] == 'O')
			data->collect = data->collect - 1;
		data->map[data->y][data->x] = '0';
		data->y = data->y - 1;
		data->map[data->y][data->x] = 'U';
		data->counter++;
	}
	else if (c == 'L' && data->map[data->y][data->x - 1] != '1' && 
				data->map[data->y][data->x - 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'C' ||
				data->map[data->y][data->x - 1] == 'O')
			data->collect = data->collect - 1;
		data->map[data->y][data->x] = '0';
		data->x = data->x - 1;
		data->map[data->y][data->x] = 'L';
		data->counter++;
	}
}

void	get_ppos(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'P')
			{
				data->x = i;
				data->y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	get_counter(t_data *data)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	data->collect = count;
}
