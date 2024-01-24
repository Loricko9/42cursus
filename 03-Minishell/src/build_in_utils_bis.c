/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_utils_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:22:46 by arthur            #+#    #+#             */
/*   Updated: 2024/01/24 16:07:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(char *line)
{
	int 	i;
	char	*name;

	i = 0;
	while(line[i] != '=')
		i++;
	name = malloc(sizeof(char) * (i + 1));
	i = 0;
	while(line[i] != '=')
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}
