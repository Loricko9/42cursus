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

float time_diff(struct timeval *start, struct timeval *end)
{
	return (end->tv_sec - start->tv_sec) * 1e3 + 1e-3 * (end->tv_usec - start->tv_usec);
}

void	*func2(void *src)
{
	fprintf(stderr, "coucou : 2\n");
	return (src);
}

void	*func1(void *src)
{
	t_data	*data;

	data = src;
	pthread_mutex_lock(&data->victory.mutex_victory);
	fprintf(stderr, "coucou : %d\n", data->victory.nb_victory);
	data->victory.nb_victory--;
	pthread_mutex_unlock(&data->victory.mutex_victory);
	return (src);
}

int	ft_fill_data(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	if (data->nb_philo < 0)
		return (1);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->victory.nb_victory = ft_atoi(av[5]);
	else
		data->victory.nb_victory = -1;
	pthread_mutex_init(&data->victory.mutex_victory, NULL);
	data->th = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->th)
		return (1);
	return (0);
}

int	ft_create(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->th[i], NULL, func1, data) != 0)
			return (1);
		if (pthread_detach(data->th[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Error : missing arg\n"));
	if (check_arg(av) == 1)
		return (1);
	if (ft_fill_data(&data, av) == 1)
		return (1);
	gettimeofday(&data.start, NULL);
	if (ft_create(&data) == 1)
		return (1);
	while (data.victory.nb_victory != 0)
		usleep(1);
	free(data.th);
}
