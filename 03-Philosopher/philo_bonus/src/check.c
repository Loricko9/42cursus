/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:37 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/18 20:08:56 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	*check_philo(void *src)
{
	t_data	*data;

	data = (t_data *)src;
	while (1)
	{
		if (data->victory == 0)
		{
			data->state = 0;
			return (NULL);
		}
		if (get_time() - data->last_eat >= data->t_die)
		{
			sem_wait(data->write);
			printf("%ld\t%d \033[31mdead\033[0m\n", get_time() - data->start,
				data->process);
			data->state = -1;
			return (NULL);
		}
		usleep(20);
	}
}
