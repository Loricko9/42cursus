/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:34:14 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/03 15:06:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count(long n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*str;

	nb = n;
	i = 2 + ft_count(nb);
	if (nb < 0)
		nb = nb * -1;
	str = malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	str[i - 1] = '\0';
	i = i - 2;
	while (nb / 10 != 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	str[i] = nb % 10 + 48;
	if (i == 1)
		str[0] = '-';
	return (str);
}

void	ft_put_nb3(t_data *data, int count, int *iter)
{
	if (count % 10 == 7)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite.sept.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
	else if (count % 10 == 8)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite.h.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
	else if (count % 10 == 9)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprite.n.img_ptr, 110 + *iter, 10);
		*iter = *iter + 11;
	}
}

void	show_counter(t_data *data)
{
	char	*str;
	int		i;
	int		iter;

	str = ft_itoa(data->counter);
	i = 0;
	iter = 0;
	while (str[i] != '\0')
	{
		ft_put_nb(data, str[i] - 48, &iter);
		i++;
	}
	free(str);
}

void	clear_nb_sprite(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprite.z.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.u.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.d.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.t.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.q.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.c.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.six.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.sept.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.h.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite.n.img_ptr);
}
