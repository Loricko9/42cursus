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

//fonction pwd du shell
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
	exit(0);
}

//fonction echo du shell
void	ft_echo(char *line)
{
	char	**temp;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	temp = ft_split(line, " ", 0);
	if (ft_strcmp_shell(temp[1], "-n", 0) == 1)
	{
		i++;
		flag = 1;
	}
	while (temp[i] != NULL)
	{
		ft_putstr(temp[i], 1);
		i++;
		if (temp[i] != NULL)
			ft_putchar(' ', 1);
	}
	if (flag == 0)
		ft_putchar('\n', 1);
	exit(0);
}

/*void	ft_cd(char **tab, char *line)
{
	
}
*/
void	ft_export(char ***tab, char *line)
{
	char	**temp;
	char	*name;
	int		index;
	int		i;

	temp = ft_split(line, " ", 0);
	i = 0;
	if (temp[1] == NULL)
		print_export(*tab);
	else
	{
		while (temp[++i] != NULL)
		{
			name = get_var_name(temp[i]);
			index = is_exported(*tab, name);
			if (index == -1)
				*tab = add_index(*tab, temp[i]);
			else
				*tab = mod_index(*tab, index, temp[i]);
			free(name);
		}	
	}
	free(temp[0]);
	free(temp);
}

void	print_export(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("declare -x %s\n", tab[i]);
		i++;
	}
}