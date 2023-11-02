/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:56:41 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/30 14:56:41 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pix_ptr;
	int		bits_per_pix;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_sprite
{
	t_img	plot;
	t_img	jerrican;
	t_img	empty;
	t_img	car_left;
	t_img	car_up;
	t_img	car_down;
	t_img	car_right;
	t_img	garage_close;
	t_img	garage_open;
	t_img	counter;
	t_img	victory;
	t_img	z;
	t_img	u;
	t_img	d;
	t_img	t;
	t_img	q;
	t_img	c;
	t_img	six;
	t_img	sept;
	t_img	h;
	t_img	n;
}	t_sprite;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_sprite	sprite;
	int			x;
	int			y;
	int			counter;
	int			collect;
}	t_data;

//utils_lst.c
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

//get_map.c
int		my_ft_strlen(char *str);
char	**get_map(int fd);
char	**fill_map(char **map, t_list *list);
void	fill_list(int fd, t_list **list);

//check_map.c
int		check_map(char **map);
int		check_char(char **map);
int		check_wall(char **map);
int		check_wall2(char **map, int j, int end);
void	free_map(char **map);

//check_map2.c
int		check_path(char **map);
int		get_path(char **map, int j, int i, long long iter);
int		check_char2(char **map);
void	check_char_spe(char car, int *e, int *c, int *p);

//display.c
int		ft_display(char **map);
void	ft_show_image(char **map, t_data *data);
void	ft_choose_sprite(char c, t_data *data, int j, int i);
void	ft_choose_car(char c, t_data *data, int j, int i);
int		ft_key(int key, t_data *data);

//display_utils.c
int		ft_size(char **map, int n);
void	finish_img(t_data *data);
int		ft_clear_display(t_data *data);
void	ft_put_nb(t_data *data, int count, int *iter);
void	ft_put_nb2(t_data *data, int count, int *iter);

//display_utils2.c
void	ft_put_nb3(t_data *data, int count, int *iter);
void	show_counter(t_data *data);
char	*ft_itoa(int n);

//edit_map.c
void	get_ppos(t_data *data);
void	ft_move(t_data *data, char c);
void	ft_move2(t_data *data, char c);
void	ft_garage(t_data *data);
void	get_counter(t_data *data);

//ini_img.c
void	ft_ini_img(t_data *data);
void	ft_ini_img2(t_data *data, int *i, int *j);
void	ft_ini_img3(t_data *data, int *i, int *j);
void	ft_ini_img4(t_data *data, int *i, int *j);
void	ft_ini_img5(t_data *data, int *i, int *j);

#endif