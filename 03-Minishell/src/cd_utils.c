/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:11:35 by arthur            #+#    #+#             */
/*   Updated: 2024/02/02 17:38:10 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(char ***tab)
{
	char	*pwd;
	char	path[1024];
	int		index;
	
	getcwd(path, 1024);
	pwd = ft_strjoin("PWD=", path);
	index = is_exported(*tab, "PWD", 0);
	old_pwd(tab);
	if (index != -1)
		*tab = mod_index(*tab, index, pwd);
	else
		*tab = add_index(*tab, pwd);
}

void	set_pwd(char ***tab)
{
	char	*pwd;
	char	path[1024];
	int		index;
	
	getcwd(path, 1024);
	pwd = ft_strjoin("PWD=", path);
	index = is_exported(*tab, "PWD", 0);
	if (index != -1)
		*tab = mod_index(*tab, index, pwd);
	else
		*tab = add_index(*tab, pwd);
}

void	tilde_manage(char ***tab, char **temp)
{
	char	*vaguelette;
	int		index;
	char	*value;
	
	index = is_exported(*tab, "HOME", 0);
	if (index == -1)
	{
		printf("\033[1;91mminishell:\033[0;91m cd:\033[0m");
		printf(" HOME not set !\n");
		return ;
	}
	value = get_var_value((*tab)[index]);
	chdir(value);
	if (temp[1][1] != '\0')
	{
		vaguelette = temp[1] + 2;
		if (chdir(vaguelette) == -1)
		{
			value  = get_var_value((*tab)[is_exported(*tab, "PWD", 0)]);
			chdir(value);
			printf("\033[1;91mminishell:\033[0;91m cd: %s:\033[0m", temp[1]);
			printf(" No such file or directory !\n");
		}
	}
	free(value);
	update_pwd(tab);
}

void	oldpwd_manage(char ***tab, char *line)
{
	int		index;
	char	*value;

	index = is_exported(*tab, "OLDPWD", 0);
	if (line[1] != '\0')
	{
		printf("\033[1;91mminishell:\033[0;91m cd:\033[0m");
		printf(" invalid option !\n");
		return ;
	}
	if (index != -1)
	{
		value = get_var_value((*tab)[index]);
		chdir(value);
		update_pwd(tab);
		free(value);
	}
	else
	{
		printf("\033[1;91mminishell:\033[0;91m cd:\033[0m");
		printf(" OLDPWD not set !\n");
	}
	
}

void	old_pwd(char ***tab)
{
	char	*pwd;
	char	*oldpwd;
	int		index;
	
	pwd = (*tab)[is_exported(*tab, "PWD", 0)];
	oldpwd = ft_strjoin("OLD", pwd);
	index = is_exported(*tab, "OLDPWD", 0);
	if (index != -1)
		*tab = mod_index(*tab, index, oldpwd);
	else
		*tab = add_index(*tab, oldpwd);
}