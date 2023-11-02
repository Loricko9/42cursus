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
	else if (key == XK_Down)
		ft_move(data, 'D');
	else if (key == XK_Up)
		ft_move(data, 'U');
	else if (key == XK_Right)
		ft_move(data, 'P');
	else if (key == XK_Left)
		ft_move(data, 'L');
	ft_printf("collect : %d\n", data->collect);
	if (data->collect == 0)
		ft_garage(data);
	ft_show_image(data->map, data);
	return (0);
}

void	ft_choose_sprite(char c, t_data *data, int j, int i)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.plot.img_ptr, i * 64, j * 64);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.empty.img_ptr, i * 64, j * 64);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.jerrican.img_ptr, i * 64, j * 64);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.garage_close.img_ptr, i * 64, j * 64);
	else if (c == 'O')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.garage_open.img_ptr, i * 64, j * 64);
	else if (c == 'P' || c == 'L' || c == 'U' || c == 'D')
		ft_choose_car(c, data, j, i);
}

void	ft_choose_car(char c, t_data *data, int j, int i)
{
	if (c == 'D')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.car_down.img_ptr, i * 64, j * 64);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.car_right.img_ptr, i * 64, j * 64);
	else if (c == 'L')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.car_left.img_ptr, i * 64, j * 64);
	else if (c == 'U')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.car_up.img_ptr, i * 64, j * 64);
}

void	ft_show_image(char **map, t_data *data)
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
	get_ppos(&data);
	get_counter(&data);
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
	ft_show_image(map, &data);
	mlx_hook(data.win, 17, 0L, ft_clear_display, &data);
	mlx_key_hook(data.win, ft_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
