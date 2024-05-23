/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:45:54 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/04 18:41:24 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	door_check(t_data *data, t_algo *algo)
{
	if (data->map[algo->map_posy][algo->map_posx] == 'D')
	{
		if (algo->side == 0 && algo->dist_temp_rayy > algo->dist_temp_rayx
			- (algo->delta_distx * 0.5))
		{
			algo->texture = 4;
			algo->dist_temp_rayx += (algo->delta_distx * 0.5);
			return (1);
		}
		else if (algo->side == 1 && algo->dist_temp_rayx > algo->dist_temp_rayy
			- (algo->delta_disty * 0.5))
		{
			algo->texture = 4;
			algo->dist_temp_rayy += (algo->delta_disty * 0.5);
			return (1);
		}
	}
	return (0);
}

void	draw_crossair(t_data *data)
{
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) - 3, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) - 2, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) - 1, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) - 1, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) - 2, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) - 3, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, WIN_X / 2, WIN_Y / 2, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) + 3, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) + 2, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) + 1, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) + 1, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) + 2, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) + 3, (WIN_Y / 2), 0xffffff);
	show_pov(data);
	display_heart(data);
}

void	show_pov2(t_data *data)
{
	if (data->textures.add_pov == 0)
		data->textures.way_pov = 1;
	else if (data->textures.add_pov == 40)
		data->textures.way_pov = 0;
	if (data->textures.way_pov == 1)
		data->textures.add_pov++;
	else if (data->textures.way_pov == 0)
		data->textures.add_pov--;
	if (data->textures.tex_pov > 20)
		data->textures.tex_pov = 0;
	else if (data->textures.tex_pov > 0)
		data->textures.tex_pov++;
}

void	show_pov(t_data *data)
{
	int	x;
	int	y;
	int	x_spr;
	int	y_spr;

	y = ((WIN_Y - 192) + (data->textures.add_pov / 4)) - 1;
	y_spr = -1;
	while ((++y_spr, ++y) < WIN_Y)
	{
		x = ((WIN_X / 2) - 96) - 1;
		x_spr = -1;
		while ((++x_spr, ++x) < (WIN_X / 2) + 96)
		{
			if (data->textures.tex_pov == 0 && take_pix(&data->textures.pov,
					x_spr / 3, y_spr / 3) != 0x000000)
				img_pixel_put(&data->img_win, x, y,
					take_pix(&data->textures.pov, x_spr / 3, y_spr / 3));
			else if (data->textures.tex_pov > 0
				&& take_pix(&data->textures.shoot_pov, x_spr / 3, y_spr / 3)
				!= 0x000000)
				img_pixel_put(&data->img_win, x, y,
					take_pix(&data->textures.shoot_pov, x_spr / 3, y_spr / 3));
		}
	}
	show_pov2(data);
}
