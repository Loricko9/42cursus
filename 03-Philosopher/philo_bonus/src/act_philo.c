/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:41:36 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/19 16:34:05 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_phil(long time, int philo, char *str, t_data *data)
{
	if (data->state == 1)
	{
		sem_wait(data->write);
		printf("%ld\t%d %s\n", time, philo, str);
		sem_post(data->write);
	}
}

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
	if (data->state != 1)
		return ;
	print_phil(get_time() - data->start, data->process, "take fork", data);
	sem_wait(data->fork);
	if (data->state != 1)
		return ;
	print_phil(get_time() - data->start, data->process, "take fork", data);
	if (data->state != 1)
		return ;
	print_phil(get_time() - data->start, data->process, "eat", data);
	data->last_eat = get_time();
	ft_sleep(data->t_eat, data, get_time());
	if (data->state != 1)
		return ;
	sem_post(data->fork);
	sem_post(data->fork);
	if (data->victory > 0)
		data->victory = data->victory - 1;
}
