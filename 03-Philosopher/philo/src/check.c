/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:37 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/14 19:11:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(char **av)
{
	int	j;

	j = 0;
	while (av[++j] != NULL)
	{
		if (ft_atoi(av[j]) > 2147483647 || ft_atoi(av[j]) <= 0)
			return (1);
	}
	return (0);
}

int	check_char(char **av)
{
	int	i;
	int	j;
	int	trig;

	j = 0;
	while (av[++j] != NULL)
	{
		i = -1;
		trig = 0;
		while (av[j][++i] != '\0')
		{
			if (((av[j][i] < '0' || av[j][i] > '9') && av[j][i] != '+') &&
					((av[j][i] < '\t' || av[j][i] > '\r') && av[j][i] != 32))
				return (1);
			else if (trig == 2 && (av[j][i] < '\t' || av[j][i] > '\r')
					&& av[j][i] != 32)
				return (1);
			else if (trig == 1 && (av[j][i] < '0' || av[j][i] > '9'))
				trig = 2;
			else if (trig == 0 && ((av[j][i] >= '0' && av[j][i] <= '9')
					|| av[j][i] == '+'))
				trig = 1;
		}
	}
	return (0);
}

int	check_victory(t_philo *lst)
{
	t_philo	*first;

	first = lst;
	pthread_mutex_lock(&lst->victory.mutex_vict);
	if (lst->victory.victory > 0 || lst->victory.victory == -1)
		return (pthread_mutex_unlock(&lst->victory.mutex_vict), 0);
	pthread_mutex_unlock(&lst->victory.mutex_vict);
	lst = lst->next;
	while (lst != first)
	{
		pthread_mutex_lock(&lst->victory.mutex_vict);
		if (lst->victory.victory > 0)
			return (pthread_mutex_unlock(&lst->victory.mutex_vict), 0);
		pthread_mutex_unlock(&lst->victory.mutex_vict);
		lst = lst->next;
	}
	return (1);
}

void	check_death(t_philo *lst, t_data *data)
{
	int		i;
	t_philo	*first;

	first = lst;
	i = 0;
	while (i < ft_lstsize(first))
	{
		pthread_mutex_lock(&lst->eat.mutex_eat);
		if (get_time() - lst->eat.last_eat >= data->t_die && lst->live == 1)
		{
			pthread_mutex_lock(&data->state.mutex_state);
			data->state.state = 0;
			pthread_mutex_unlock(&data->state.mutex_state);
			pthread_mutex_unlock(&lst->eat.mutex_eat);
			usleep(1000);
			pthread_mutex_lock(&data->writing);
			printf("%ld\t%d \033[31mdead\033[0m\n", get_time() - data->start
				- 1, lst->nb_philo);
			pthread_mutex_unlock(&data->writing);
			return ;
		}
		pthread_mutex_unlock(&lst->eat.mutex_eat);
		i++;
	}
	return ;
}

void	check_philo(t_philo *lst, t_data *data)
{
	while (1)
	{
		check_death(lst, data);
		if (check_victory(lst) == 1)
		{
			pthread_mutex_lock(&data->state.mutex_state);
			data->state.state = 0;
			pthread_mutex_unlock(&data->state.mutex_state);
		}
		if (check_state(data) == 0)
			break ;
		usleep(10);
	}
}
