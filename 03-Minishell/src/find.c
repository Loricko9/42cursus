/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:00:12 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/11 15:00:12 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char*	extract_pwd(char **env)
{
	int	j;

	j = 0;
	while (ft_strcmp_shell(env[j], "PWD=") == 0)
		j++;
	
}*/

int	find_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '|')
			return (1);
		i++;
	}
	return (0);
}
