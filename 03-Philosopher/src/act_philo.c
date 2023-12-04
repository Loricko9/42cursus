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

float time_diff(struct timeval *start, struct timeval *end)
{
	return (end->tv_sec - start->tv_sec) * 1e3 + 1e-3
		* (end->tv_usec - start->tv_usec);
}

void	act_death2(t_philo *lst)
{
	struct timeval	end;
	
	lst->death.death -= 0.01;
	usleep(10);
	if (lst->death.death <= 0)
	{
		lst->data->state = 0;
		gettimeofday(&end, NULL);
		printf("%f | philo %d dead\n", time_diff(&lst->data->start, &end), lst->nb_philo);
	}
}

void	act_death(t_philo *lst)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	if (lst->death.last_act.tv_sec == 0 && lst->death.last_act.tv_usec == 0)
		lst->death.death -= time_diff(&lst->data->start, &end);
	else
		lst->death.death -= time_diff(&lst->death.last_act, &end);
	lst->death.last_act = end;
	/*if (lst->nb_philo == 1)
		printf("time %f\n", lst->death.death);*/
	if (lst->death.death <= 0)
	{
		lst->data->state = 0;
		printf("%f | philo %d dead\n", time_diff(&lst->data->start, &lst->death.last_act), lst->nb_philo);
	}
}
