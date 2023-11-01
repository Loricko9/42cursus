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
	mlx_destroy_image(data->mlx, data->jerrican.img_ptr);
	mlx_destroy_image(data->mlx, data->empty.img_ptr);
	mlx_destroy_image(data->mlx, data->plot.img_ptr);
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
	int i;
	int j;
	
	j = 64;
	i = 64;
	data->plot.img_ptr = mlx_xpm_file_to_image(data->mlx, "textures/Plot.xpm", &i, &j);
	data->plot.img_pix_ptr = mlx_get_data_addr(data->mlx, &data->plot.bits_per_pix, &data->plot.line_len, &data->plot.endian);
	data->jerrican.img_ptr = mlx_xpm_file_to_image(data->mlx, "textures/Jerrican.xpm", &i, &j);
	data->jerrican.img_pix_ptr = mlx_get_data_addr(data->mlx, &data->jerrican.bits_per_pix, &data->jerrican.line_len, &data->jerrican.endian);
	data->empty.img_ptr = mlx_xpm_file_to_image(data->mlx, "textures/Empty.xpm", &i, &j);
	data->empty.img_pix_ptr = mlx_get_data_addr(data->mlx, &data->empty.bits_per_pix, &data->empty.line_len, &data->empty.endian);
}

