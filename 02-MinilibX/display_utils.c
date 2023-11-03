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
	clear_nb_sprite(data);
	mlx_destroy_image(data->mlx, data->sprite.jerrican.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.empty.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.plot.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_down.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_left.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_right.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.car_up.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.garage_close.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.garage_open.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.victory.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.counter.img_ptr);
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

void	finish_img(t_data *data)
{
	int	y;
	int	x;

	y = ft_size(data->map, 0);
	x = ft_size(data->map, 1);
	mlx_put_image_to_window(data->mlx, data->win, 
		data->sprite.victory.img_ptr, (x / 2) - 128, (y / 2) - 64);
}

void	ft_put_nb(t_data *data, int count, int *iter)
{
	if (count % 10 == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.z.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
	else if (count % 10 == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.u.img_ptr, 110 + *iter, 10);
		*iter = *iter + 9;
	}
	else if (count % 10 == 2)
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.d.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
	ft_put_nb2(data, count, iter);
	ft_put_nb3(data, count, iter);
}

void	ft_put_nb2(t_data *data, int count, int *iter)
{
	if (count % 10 == 3)
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.t.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
	else if (count % 10 == 4)
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.q.img_ptr, 110 + *iter, 10);
		*iter = *iter + 13;
	}
	else if (count % 10 == 5)
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.c.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
	else if (count % 10 == 6)
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->sprite.six.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
}
