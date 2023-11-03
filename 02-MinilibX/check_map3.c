/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:34 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/03 17:04:34 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_path2(char **map, t_pos *pos, int *top, t_pos cur)
{
	if (map[cur.j][cur.i + 1] != '1' && map[cur.j][cur.i + 1] != '2')
	{
		pos[*top].j = cur.j;
		pos[*top].i = cur.i + 1;
		*top = *top + 1;
		map[cur.j][cur.i + 1] = '2';
	}
	if (map[cur.j - 1][cur.i] != '1' && map[cur.j - 1][cur.i] != '2')
	{
		pos[*top].j = cur.j - 1;
		pos[*top].i = cur.i;
		map[cur.j - 1][cur.i] = '2';
		*top = *top + 1;
	}
	if (map[cur.j][cur.i - 1] != '1' && map[cur.j][cur.i - 1] != '2')
	{
		pos[*top].j = cur.j;
		pos[*top].i = cur.i - 1;
		map[cur.j][cur.i - 1] = '2';
		*top = *top + 1;
	}
}
