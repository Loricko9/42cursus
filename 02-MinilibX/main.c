/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:56:46 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/30 14:56:46 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	
	if (ac != 2)
		return (1);
	map = get_map(open(av[1], O_RDONLY));
	if (!map)
		return (ft_printf("Memmory alloc ERROR !\n"));
	/*while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}*/
	if (check_map(map) == 1)
		return (ft_printf("Map ERROR !\n"));
	if (ft_display(map) == 1)
		return (ft_printf("Display ERROR !"));
}
