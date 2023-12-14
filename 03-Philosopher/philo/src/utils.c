/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:30:16 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/14 19:12:11 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_state(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->state.mutex_state);
	res = data->state.state;
	pthread_mutex_unlock(&data->state.mutex_state);
	return (res);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * sign);
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
			return (ft_free(*lst, NULL), 1);
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
	pthread_mutex_init(&data->state.mutex_state, NULL);
	pthread_mutex_init(&data->writing, NULL);
	data->state.state = 0;
	return (0);
}

void	print_mutx(int philo, long tps, t_data *data, char *str)
{
	if (check_state(data) == 1)
	{
		pthread_mutex_lock(&data->writing);
		printf("%ld\t%d %s\n", tps, philo, str);
		pthread_mutex_unlock(&data->writing);
	}
}
