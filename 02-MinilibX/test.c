#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pix_ptr;
	int		bits_per_pix;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_data;

#define WIDTH	400
#define HEIGHT	400

void	my_pix_put(t_img *img, int x, int y, int color)
{
	int	add;

	add = ((y * img->line_len) + (x * (img->bits_per_pix / 8)));
	*((unsigned int *)(add + img->img_pix_ptr)) = color;
}

void	color_win(t_data *data, int color)
{
	int	x;
	int y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			my_pix_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}

}

int	key_press(int key, t_data *data)
{
	if (key == XK_r)
		color_win(data, 0xff0000);
	else if (key == XK_b)
		color_win(data, 0xff00);
	else if (key == XK_g)
		color_win(data, 0xff);
	else if (key == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Ma fenetre batard");
	if (data.mlx == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
	}
	data.img.img_ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.img_pix_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pix, &data.img.line_len, &data.img.endian);
	mlx_key_hook(data.win, key_press, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

