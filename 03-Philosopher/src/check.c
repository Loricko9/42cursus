/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:37 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/28 17:13:37 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(char **av)
{
	int	j;

	j = 0;
	while (av[++j] != NULL)
	{
		if (ft_atoi(av[j]) > 2147483647)
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
				trig =2;
			else if (trig == 0 && ((av[j][i] >= '0' && av[j][i] <= '9')
					|| av[j][i] == '+'))
				trig = 1;
		}
	}
	return (0);
}

int	check_arg(char **av)
{
	if (check_char(av) == 1)
		return (printf("Error : invalid char\n"), 1);
	if (check_int(av) == 1)
		return (printf("Error : nb to high\n"), 1);
	return (0);
}

int	check_victory(t_philo *lst)
{
	t_philo	*first;

	first = lst;
	if (lst->victory > 0 || lst->victory == -1)
		return (0);
	lst = lst->next;
	while (lst != first)
	{
		if (lst->victory > 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_philo(t_philo *lst, t_data *data)
{
	int		i;
	t_philo	*first;

	first = lst;
	while (data->state != 0)
	{
		i = 0;
		while (i < ft_lstsize(first))
		{
			if (get_time() - lst->last_eat >= data->t_die && lst->live == 1)
				return (printf("%ld | %d DEAD !!!!!!!!\n", get_time() - data->start, lst->nb_philo), data->state = 0, 0);
			i++;
		}
		if (check_victory(lst) == 1)
			data->state = 0;
	}
	if (check_victory(lst) == 1)
		printf("Victory !!!!\n");
	return (1);
}

