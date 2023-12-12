/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:41:36 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/04 17:41:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_time(void)
{
	struct timeval	end;
	
	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000) + (end.tv_usec / 1000));
}

void	ft_sleep(int t_ms, t_data *data)
{
	long	start;
	long	time;
	long	last_act;

	time = t_ms;
	last_act = get_time();
	while (time > 0 && data->state == 1)
	{
		start = get_time();
		time = time - (start - last_act);
		last_act = start;
	}
}

void	wait_philo(t_philo *lst, t_data *data)
{
	if (data->size % 2 == 0)
	{
		if (lst->nb_philo % 2 == 1)
			return ;
		else
			ft_sleep(data->t_eat, data);
	}
	else
	{
		if (lst->nb_philo == data->size)
			ft_sleep(data->t_eat * 2, data);
		else if (lst->nb_philo % 2 == 1)
			return ;
		else
			ft_sleep(data->t_eat, data);
	}
}

void	take_fork(t_philo *lst, t_data *data)
{
	t_philo	*next;

	next = lst->next;
	pthread_mutex_lock(&lst->mutex_fork);
	printf("%ld | %d take fork\n", get_time() - data->start, lst->nb_philo);
	pthread_mutex_lock(&next->mutex_fork);
	printf("%ld | %d take fork\n", get_time() - data->start, lst->nb_philo);
	printf("%ld | %d eating\n", get_time() - data->start, lst->nb_philo);
	ft_sleep(data->t_eat, data);
	pthread_mutex_unlock(&lst->mutex_fork);
	pthread_mutex_unlock(&next->mutex_fork);
	lst->last_eat = get_time();
	if (data->state == 0)
		return ;
	if (lst->victory > 0)
		lst->victory = lst->victory - 1;
}
