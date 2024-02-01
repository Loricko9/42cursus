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
void	ft_pwd(void)
{
	char path[1024];
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
	free(line);
}

void	ft_unset(char ***tab, char *line)
{
	char	**temp;
	int		index;
	int		i;

	i = 0;
	temp = ft_split(line, " ", 0);
	while (temp[i] != NULL)
	{
		index = is_exported(*tab, get_var_name(temp[i]));
		if (index != -1)
			*tab = rm_index(*tab, index);
		i++;
	}
}

void	ft_export(char ***tab, char *line)
{
	char	**temp;
	int		index;
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
		index = is_exported(*tab, get_var_name(temp[i]));
		if (index == -1)
			*tab = add_index(*tab, temp[i]);
		else
		{
			if (is_var_empty(temp[i]) != 2)
				*tab = mod_index(*tab, index, temp[i]);
		}
	}
	free(temp[0]);
	free(temp);
}

void	ft_cd(char ***tab, char **tab_bis, char *line)
{
	char	**temp;
	char	path[1024];
	char	*pwd;

	temp = ft_split(line, " ", 0);
	if (temp[1] == NULL)
	{
		chdir(get_var_value(tab_bis[is_exported(tab_bis, "HOME")]));
	}
	else
	{
		if (chdir(temp[1]) == -1)
		{
			printf("\033[1;91mminishell:\033[0;91m cd: %s:\033[0m", temp[1]);
			printf(" No such file or directory !\n");
		}
		else
		{		
			getcwd(path, 1024);
			pwd = ft_strjoin("PWD=", path);
			*tab = mod_index(*tab, is_exported(*tab, "PWD"), pwd);
		}
	}
	ft_free_tab(temp);
}


