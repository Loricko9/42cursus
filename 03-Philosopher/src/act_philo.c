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

void	act_death(t_philo *lst)
{
	/*if (lst->nb_philo == 1)
		printf("time %f\n", lst->death.death);*/
	long	time;
	time = get_time();
	if (lst->death.last_act == -1)
		lst->death.death = lst->death.death - (time - lst->data->start);
	else
		lst->death.death = lst->death.death - (time - lst->death.last_act);
	/*if (lst->nb_philo == 1 && lst->death.last_act != -1)
		printf("----diff : %ld----\n----remain : %ld----\n", (time - lst->death.last_act), lst->death.death);*/
	lst->death.last_act = time;
	if (lst->death.death <= 0)
	{
		lst->data->state = 0;
		printf("%ld | philo %d dead\n", get_time() - lst->data->start, lst->nb_philo);
	}
}

void	wait_philo(t_philo *lst, t_data *data)
{
	//long time;

	//time = data->t_eat;	
	if (data->size % 2 == 0)
	{
		if (lst->nb_philo % 2 == 1)
			return ;
		else
			usleep(data->t_eat * 1000);
	}
	else
	{
		if (lst->nb_philo == data->size)
			usleep(data->t_eat * 1000 * 2);
		else if (lst->nb_philo % 2 == 1)
			return ;
		else
			usleep(data->t_eat * 1000);
	}
}

void	take_fork(t_philo *lst, t_data *data)
{
	t_philo	*next;
	long	time_eat;
	long	last_act;
	long	time;

	next = lst->next;
	time_eat = data->t_eat;
	pthread_mutex_lock(&lst->mutex_fork);
	pthread_mutex_lock(&next->mutex_fork);	
	printf("%ld | philo %d take fork\n", get_time() - data->start, lst->nb_philo);
	printf("%ld | philo %d take fork\n", get_time() - data->start, lst->nb_philo);
	last_act = get_time();
	while (time_eat > 0 && data->state != 0)
	{
		act_death(lst);
		//printf("time : %ld\n", time_eat);
		time = get_time();
		time_eat = time_eat - (time - last_act);
		last_act = time;
	}
	pthread_mutex_unlock(&lst->mutex_fork);
	pthread_mutex_unlock(&next->mutex_fork);
	lst->death.death = data->t_die;
	if (data->state == 0)
		return ;
	act_vitcory(lst);
	sleep_philo(lst, data);
}

void	sleep_philo(t_philo *lst, t_data *data)
{
	long	time_sleep;
	long	last_act;
	long	time;

	time_sleep = data->t_sleep;
	last_act = get_time();
	//printf("time after : %ld\n", data->start);
	//printf("get_time : %ld\n", get_time());
	printf("%ld | philo %d sleep\n", last_act - data->start, lst->nb_philo);
	while (time_sleep > 0 && data->state != 0)
	{
		act_death(lst);
		time = get_time();
		time_sleep = time_sleep - (time - last_act);
		last_act = time;
	}
	if (data->state == 0)
		return ;
	printf("%ld | philo %d think\n", last_act - data->start, lst->nb_philo);
}
