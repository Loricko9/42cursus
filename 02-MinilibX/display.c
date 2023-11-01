/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:32:36 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/01 15:32:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_clear_display(data);
	return (0);
}

void	ft_choose_sprite(char c, t_data *data, int j, int i)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->plot.img_ptr, i * 64, j * 64);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->empty.img_ptr, i * 64, j * 64);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->jerrican.img_ptr, i * 64, j * 64);
}

void	ft_first_image(char **map, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			ft_choose_sprite(map[j][i], data, j, i);
			i++;
		}
		j++;
	}
}

int	ft_display(char **map)
{
	t_data	data;

	data.mlx = mlx_init();
	data.map = map;
	if (data.mlx == NULL)
	{
		free_map(map);
		return (1);
	}
	data.win = mlx_new_window(data.mlx, ft_size(map, 1), ft_size(map, 0), "Need For Speed 1950");
	if (data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		free_map(map);
		return (1);
	}
	ft_ini_img(&data);
	ft_first_image(map, &data);
	mlx_hook(data.win, 17, 0L, ft_clear_display, &data);
	mlx_key_hook(data.win, ft_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
