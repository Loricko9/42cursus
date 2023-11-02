/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:35:45 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/02 18:35:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_ini_img3(data, &i, &j);
	ft_ini_img4(data, &i, &j);
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
			&data->sprite.garage_close.line_len, 
			&data->sprite.garage_close.endian);
}

void	ft_ini_img3(t_data *data, int *i, int *j)
{
	data->sprite.garage_open.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Garage_open.xpm", i, j);
	data->sprite.garage_open.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.garage_open.bits_per_pix, 
			&data->sprite.garage_open.line_len, 
			&data->sprite.garage_open.endian);
	data->sprite.victory.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Victory.xpm", i, j);
	data->sprite.victory.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.victory.bits_per_pix, 
			&data->sprite.victory.line_len, &data->sprite.victory.endian);
	data->sprite.counter.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/Counter.xpm", i, j);
	data->sprite.counter.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.counter.bits_per_pix, 
			&data->sprite.counter.line_len, &data->sprite.counter.endian);
	data->sprite.z.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/0.xpm", i, j);
	data->sprite.z.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.z.bits_per_pix, 
			&data->sprite.z.line_len, &data->sprite.z.endian);
	data->sprite.u.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/1.xpm", i, j);
}

void	ft_ini_img4(t_data *data, int *i, int *j)
{
	data->sprite.u.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.u.bits_per_pix, 
			&data->sprite.u.line_len, &data->sprite.u.endian);
	data->sprite.d.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/2.xpm", i, j);
	data->sprite.d.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.d.bits_per_pix, 
			&data->sprite.d.line_len, &data->sprite.d.endian);
	data->sprite.t.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/3.xpm", i, j);
	data->sprite.t.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.t.bits_per_pix, 
			&data->sprite.t.line_len, &data->sprite.t.endian);
	data->sprite.q.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/4.xpm", i, j);
	data->sprite.q.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.q.bits_per_pix, 
			&data->sprite.q.line_len, &data->sprite.q.endian);
	data->sprite.c.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/5.xpm", i, j);
	data->sprite.c.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.c.bits_per_pix, 
			&data->sprite.c.line_len, &data->sprite.c.endian);
	ft_ini_img5(data, i, j);
}

void	ft_ini_img5(t_data *data, int *i, int *j)
{
	data->sprite.six.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/6.xpm", i, j);
	data->sprite.six.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.six.bits_per_pix, 
			&data->sprite.six.line_len, &data->sprite.six.endian);
	data->sprite.sept.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/7.xpm", i, j);
	data->sprite.sept.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.sept.bits_per_pix, 
			&data->sprite.sept.line_len, &data->sprite.sept.endian);
	data->sprite.h.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/8.xpm", i, j);
	data->sprite.h.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.h.bits_per_pix, 
			&data->sprite.h.line_len, &data->sprite.h.endian);
	data->sprite.n.img_ptr = mlx_xpm_file_to_image(data->mlx, 
			"textures/9.xpm", i, j);
	data->sprite.n.img_pix_ptr = mlx_get_data_addr(data->mlx, 
			&data->sprite.n.bits_per_pix, 
			&data->sprite.n.line_len, &data->sprite.n.endian);
	data->counter = 0;
}
