/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:40:26 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/16 18:40:26 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(int process, t_data *data)
{
	pthread_t	thread;

	free(data->pid);
	if (pthread_create(&thread, NULL, check_death, data) != 0)
		exit(1);
	if (pthread_detach(thread) != 0)
		exit(1);
	while (state == 1)
	{
		
	}
}

int	ft_fill_data(t_data *data, char **av)
{
	int	nb_victory;

	data->size = ft_atoi(av[1]);
	if (data->size <= 0)
		return (1);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		nb_victory = ft_atoi(av[5]);
	else
		nb_victory = -1;
	data->pid = malloc(sizeof(pid_t) * data->size);
	if (!data->pid)
		return (1);
	data->state = 0;
	return (0);
}

int ft_create(t_data *data)
{
	int	i;

	i = 0;
	data->start = get_time();
	while (i < data->size)
	{
		data->pid[i] = fork();
		data->last_act_death = get_time();
		if (data->pid[i] == 0)
			routine(i, &data);
		if (data->pid[i] == -1)
			return (kill_proc(data->pid, 0, i), 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Error : missing arg\n"));
	if (check_char(av) == 1)
		return (printf("Error : invalid char\n"), 1);
	if (check_int(av) == 1)
		return (printf("Error : wrong nb\n"), 1);
	if (ft_fill_data(&data, av) == 1)
		return (1);
	if (ft_create(&data) == 1)
		return (1);
	kill_proc(data.pid, first_pid_end());
	free(data.pid);
}
