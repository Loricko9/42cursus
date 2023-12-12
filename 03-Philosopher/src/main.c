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
	t_philo	*lst;
	t_data	*data;

	lst = src;
	data = lst->data;
	/*while (lst->data->state != 1)
		usleep(1);*/
	wait_philo(lst, lst->data);
	lst->last_eat = get_time();
	lst->live = 1;
	while (lst->data->state != 0)
	{
		take_fork(lst, lst->data);
		printf("%ld | %d sleep\n", get_time() - data->start, lst->nb_philo);
		ft_sleep(data->t_sleep, data);
		printf("%ld | %d thinking\n", get_time() - data->start, lst->nb_philo);
	}
	return (NULL);
}

int	create_lst(t_philo **lst, int nbr_philo, int nb_victory, t_data *data)
{
	int		i;
	t_philo	*last;
	t_philo	*new;

	i = 1;
	while (i <= nbr_philo)
	{
		new = ft_lstnew(i, nb_victory, data);
		if (!new)
			return (ft_lst_free(*lst), 1);
		ft_lstadd_back(lst, new);
		i++;
	}
	last = ft_lstlast(*lst);
	last->next = *lst;
	return (0);
}

int	ft_fill_data(t_data *data, char **av, t_philo **lst)
{
	int	nb_victory;
	
	if (ft_atoi(av[1]) < 0)
		return (1);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		nb_victory = ft_atoi(av[5]);
	else
		nb_victory = -1;
	*lst = NULL;
	if (create_lst(lst, ft_atoi(av[1]), nb_victory, data) == 1)
		return (1);
	data->state = 0;
	return (0);
}

int	ft_create(t_data *data, t_philo *lst)
{
	int	size;

	size = ft_lstsize(lst);
	data->size = size;
	data->state = 1;
	lst->data->start = get_time();
	while (size > 0)
	{
		if (pthread_create(&lst->thread, NULL, func1, lst) != 0)
			return (1);
		/*if (pthread_detach(lst->thread) != 0)
			return (1);*/
		lst = lst->next;
		size--;
		usleep(20);
	}
	return (0);
}

void finish_th(t_philo *lst)
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
	if (check_arg(av) == 1)
		return (1);
	if (ft_fill_data(&data, av, &lst) == 1)
		return (1);
	if (ft_create(&data, lst) == 1)
		return (1);
	check_philo(lst, &data);
	finish_th(lst);
	//print_lst(lst);
	printf("fin de la simulation\n");
	ft_lst_free(lst);
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