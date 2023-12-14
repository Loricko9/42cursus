/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:57:06 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/27 15:57:06 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func1(void *src)
{
	t_philo *lst;
	t_data *data;

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
			break;
		print_mutx(lst->nb_philo, get_time() - data->start, data, "sleep");
		if (check_state(data) == 0)
			break;
		ft_sleep(data->t_sleep, data, get_time());
		if (check_state(data) == 0)
			break;
		print_mutx(lst->nb_philo, get_time() - data->start, data, "thinking");
		if (check_state(data) == 0)
			break;
	}
	return (NULL);
}

int ft_create(t_data *data, t_philo *lst)
{
	int size;

	size = ft_lstsize(lst);
	data->size = size;
	while (size > 0)
	{
		// lst->last_eat = get_time();
		if (pthread_create(&lst->thread, NULL, func1, lst) != 0)
			return (ft_free(lst, data), 1);
		lst = lst->next;
		size--;
	}
	lst->data->start = get_time();
	pthread_mutex_lock(&data->state.mutex_state);
	data->state.state = 1;
	pthread_mutex_unlock(&data->state.mutex_state);
	return (0);
}

void finish_th(t_philo *lst)
{
	t_philo *first;

	first = lst;
	pthread_join(lst->thread, NULL);
	lst = lst->next;
	while (lst != first)
	{
		pthread_join(lst->thread, NULL);
		lst = lst->next;
	}
}

int main(int ac, char **av)
{
	t_data data;
	t_philo *lst;

	if (ac < 5 || ac > 6)
		return (printf("Error : missing arg\n"));
	if (check_arg(av) == 1)
		return (1);
	if (ft_fill_data(&data, av, &lst) == 1)
		return (1);
	if (ft_create(&data, lst) == 1)
		return (1);
	check_philo(lst, &data);
	finish_th(lst);
	ft_free(lst, &data);
}

/*void	print_lst(t_philo *lst)
{
	t_philo	*first;

	first = lst;
	printf("nb : %d\nfork : %d\neat : %d\n", lst->nb_philo, lst->mutex_fork, lst->victory.nb_victory);
	printf("---------------------------\n");
	pthread_mutex_unlock(&lst->victory.mutex_victory);
	lst = lst->next;
	while (lst != first)
	{
		pthread_mutex_lock(&lst->victory.mutex_victory);
		printf("nb : %d\nfork : %d\neat : %d\n", lst->nb_philo, lst->fork.fork, lst->victory.nb_victory);
		printf("---------------------------\n");
		pthread_mutex_unlock(&lst->victory.mutex_victory);
		lst = lst->next;
	}
}*/