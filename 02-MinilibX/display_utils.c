/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:16:04 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/01 17:16:04 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_clear_display(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprite.jerrican.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.empty.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.plot.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_down.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_left.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_right.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_up.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.garage_close.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.garage_open.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit (1);
}

int	ft_size(char **map, int n)
{
	int	i;

	i = 0;
	if (n == 1)
	{
		while (map[0][i] != '\0')
			i++;
		return (i * 64);
	}
	else
	{
		while (map[i] != NULL)
			i++;
		return (i * 64);
	}
}

void	ft_ini_img(t_data *data)
{
	int	i;
	int	j;

	j = 64;
	i = 64;
	data->sprite.plot.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/Plot.xpm", &i, &j);
	data->sprite.plot.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.plot.bits_per_pix, &data->sprite.plot.line_len, 
			&data->sprite.plot.endian);
	data->sprite.jerrican.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Jerrican.xpm", &i, &j);
	data->sprite.jerrican.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.jerrican.bits_per_pix, 
			&data->sprite.jerrican.line_len, &data->sprite.jerrican.endian);
	data->sprite.empty.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/Empty.xpm", &i, &j);
	data->sprite.empty.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.empty.bits_per_pix, &data->sprite.empty.line_len, 
			&data->sprite.empty.endian);
	data->sprite.car_down.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Car_down.xpm", &i, &j);
	ft_ini_img2(data, &i, &j);
}

void	ft_ini_img2(t_data *data, int *i, int *j)
{
	data->sprite.car_down.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.car_down.bits_per_pix, 
			&data->sprite.car_down.line_len, &data->sprite.car_down.endian);
	data->sprite.car_left.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/Car_left.xpm", i, j);
	data->sprite.car_left.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.car_left.bits_per_pix, 
			&data->sprite.car_left.line_len, &data->sprite.car_left.endian);
	data->sprite.car_right.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Car_right.xpm", i, j);
	data->sprite.car_right.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.car_right.bits_per_pix, 
			&data->sprite.car_right.line_len, &data->sprite.car_right.endian);
	data->sprite.car_up.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Car_up.xpm", i, j);
	data->sprite.car_up.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.car_up.bits_per_pix, 
			&data->sprite.car_up.line_len, &data->sprite.car_up.endian);
	data->sprite.garage_close.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Garage_close.xpm", i, j);
	data->sprite.garage_close.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.garage_close.bits_per_pix, 
			&data->sprite.garage_close.line_len, &data->sprite.garage_close.endian);
	data->sprite.garage_open.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Garage_open.xpm", i, j);
	data->sprite.garage_open.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.garage_open.bits_per_pix, 
			&data->sprite.garage_open.line_len, &data->sprite.garage_open.endian);
}
