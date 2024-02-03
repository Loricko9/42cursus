/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:53 by arthur            #+#    #+#             */
/*   Updated: 2024/02/03 16:12:46 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//fonction pwd du shell
void	ft_pwd(void)
{
	char	path[1024];

	printf("%s\n", getcwd(path, 1024));
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
	ft_free_tab(temp);
}

void	ft_unset(char ***tab, char *line)
{
	char	**temp;
	char	*name;
	int		index;
	int		i;

	i = 0;
	temp = ft_split(line, " ", 0);
	while (temp[i] != NULL)
	{
		name = get_var_name(temp[i]);
		index = is_exported(*tab, name, 1);
		if (index != -1)
			*tab = rm_index(*tab, index);
		i++;
	}
	ft_free_tab(temp);
}

void	ft_export(char ***tab, char *line)
{
	char	**temp;
	int		i;

	temp = ft_split(line, " ", 0);
	i = 0;
	if (temp[1] == NULL)
		print_export(*tab);
	while (temp[++i] != NULL)
	{
		if (ft_check_export(temp[i]) == 1)
		{
			free(temp[i]);
			continue ;
		}
		ft_export_bis(tab, temp, i);
	}
	free(temp[0]);
	free(temp);
}

void	ft_cd(char ***tab, char *line)
{
	char	**temp;
	char	*home;

	temp = ft_split(line, " ", 0);
	set_pwd(tab);
	home = get_var_value((*tab)[is_exported(*tab, "HOME", 0)]);
	if (temp[1] == NULL)
		chdir(home);
	else if (temp[2] == NULL)
	{
		ft_cd_bis(tab, temp);
	}
	else
	{
		printf("\033[1;91mminishell:\033[0;91m cd:\033[0m");
		printf(" too many arguments !\n");
	}
	free(home);
	ft_free_tab(temp);
}
