/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:41:36 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/14 19:12:24 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000) + (end.tv_usec / 1000));
}

void	ft_sleep(int t_ms, t_data *data, long start)
{
	while (get_time() - start < t_ms)
	{
		if (data->state == 0)
			break ;
		usleep(20);
	}
}

void	wait_philo(t_data *data)
{
	if (data->size % 2 == 0)
	{
		if (data->process % 2 == 1)
			return ;
		else
			ft_sleep(data->t_eat, data, get_time());
	}
	else
	{
		if (data->process == data->size)
			ft_sleep(data->t_eat * 2, data, get_time());
		else if (data->process % 2 == 1)
			return ;
		else
			ft_sleep(data->t_eat, data, get_time());
	}
}

void	take_fork(t_data *data)
{
	sem_wait(data->fork);
	printf("%ld\t%d take fork\n", get_time() - data->start, data->process);
	sem_wait(data->fork);
	printf("%ld\t%d take fork\n", get_time() - data->start, data->process);
	printf("%ld\t%d eat\n", get_time() - data->start, data->process);
	data->last_eat = get_time();
	ft_sleep(data->t_eat, data, get_time());
	sem_post(data->fork);
	sem_post(data->fork);
	if (data->victory > 0)
		data->victory = data->victory - 1;
}
