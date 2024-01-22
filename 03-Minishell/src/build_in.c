/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:53 by arthur            #+#    #+#             */
/*   Updated: 2024/01/22 16:49:08 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **tab)
{
	int i;
	char *tmp;
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp_shell(tab[i], "PWD=", 0) == 1)
		{
			tmp = tab[i];
			tmp += 4;
			printf("%s\n", tmp);
		}
		i++;
	}
}

void	ft_echo(char *line)
{
	char	**temp;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	temp = ft_split(line, " ");
	if (ft_strcmp_shell(temp[1], "-n", 0) == 1)
	{
		i++;
		flag = 1;
	}
	while (temp[i] != NULL)
	{
		ft_putstr(temp[i], 1);
		ft_putchar(' ', 1);
		i++;
	}
	if (flag == 0)
		ft_putchar('\n', 1);
}
