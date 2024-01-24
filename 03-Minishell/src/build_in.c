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
	exit(1);
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
	exit(1);
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

	temp = ft_split(line, " ", 0);
	if (temp[1] == NULL)
	{
		print_export(*tab);
	}
	else
	{
		name = get_var_name(temp[1]);
		index = is_exported(*tab, name);
//		printf("%s\n", temp[1]);
		if (index == -1)
		{
			printf("new\n");
			*tab = add_index(*tab, temp[1]);
		}
		else
		{
			printf("test\n");
			*tab = mod_index(*tab, index, temp[1]);
		}
	}
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