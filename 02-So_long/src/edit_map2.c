/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:26:49 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/03 15:08:55 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move3(t_data *data, char c)
{
	if (c == 'P' && data->map[data->y][data->x + 1] != '1'
				&& data->map[data->y][data->x + 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'C'
				|| data->map[data->y][data->x + 1] == 'O')
			data->collect = data->collect - 1;
		data->map[data->y][data->x] = '0';
		data->x = data->x + 1;
		data->map[data->y][data->x] = 'P';
		data->counter++;
	}
}
