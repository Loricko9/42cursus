/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:57:06 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/14 19:13:04 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_1phil(void *src)
{
	t_philo	*lst;
	t_data	*data;

	lst = src;
	data = lst->data;
	pthread_mutex_lock(&lst->eat.mutex_eat);
	lst->eat.last_eat = get_time();
	pthread_mutex_unlock(&lst->eat.mutex_eat);
	lst->live = 1;
	print_mutx(lst->nb_philo, get_time() - data->start, data, "take fork");
	ft_sleep(data->t_die, data, get_time());
	return (src);
}

void	*routine(void *src)
{
	t_philo	*lst;
	t_data	*data;

	lst = src;
	data = lst->data;
	wait_philo(lst, lst->data);
	pthread_mutex_lock(&lst->eat.mutex_eat);
	lst->eat.last_eat = get_time();
	pthread_mutex_unlock(&lst->eat.mutex_eat);
	lst->live = 1;
	while (1)
	{
		take_fork(lst, lst->data);
		if (check_state(data) == 0)
			break ;
		print_mutx(lst->nb_philo, get_time() - data->start, data, "sleep");
		ft_sleep(data->t_sleep, data, get_time());
		if (check_state(data) == 0)
			break ;
		print_mutx(lst->nb_philo, get_time() - data->start, data, "thinking");
	}
	return (NULL);
}

int	ft_create(t_data *data, t_philo *lst)
{
	int	size;

	size = ft_lstsize(lst);
	data->size = size;
	if (size == 1)
	{
		if (pthread_create(&lst->thread, NULL, routine_1phil, lst) != 0)
			return (ft_free(lst, data), 1);
	}
	else
	{
		while (size > 0)
		{
			if (pthread_create(&lst->thread, NULL, routine, lst) != 0)
				return (ft_free(lst, data), 1);
			lst = lst->next;
			size--;
		}
	}
	lst->data->start = get_time();
	pthread_mutex_lock(&data->state.mutex_state);
	data->state.state = 1;
	pthread_mutex_unlock(&data->state.mutex_state);
	return (0);
}

void	finish_th(t_philo *lst)
{
	t_philo	*first;

	first = lst;
	pthread_join(lst->thread, NULL);
	lst = lst->next;
	while (lst != first)
	{
		pthread_join(lst->thread, NULL);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*lst;

	if (ac < 5 || ac > 6)
		return (printf("Error : missing arg\n"));
	if (check_char(av) == 1)
		return (printf("Error : invalid char\n"), 1);
	if (check_int(av) == 1)
		return (printf("Error : wrong nb\n"), 1);
	if (ft_fill_data(&data, av, &lst) == 1)
		return (1);
	if (ft_create(&data, lst) == 1)
		return (1);
	check_philo(lst, &data);
	finish_th(lst);
	ft_free(lst, &data);
}
