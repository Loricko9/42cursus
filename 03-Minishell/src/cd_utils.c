/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:11:35 by arthur            #+#    #+#             */
/*   Updated: 2024/02/04 20:43:22 by lle-saul         ###   ########.fr       */
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

void	tilde_manage(char ***tab, char **temp, int index)
{
	char	*vaguelette;
	char	*value;

	if (index == -1)
		return ;
	value = get_var_value((*tab)[index]);
	chdir(value);
	if (temp[1][1] != '\0')
	{
		vaguelette = temp[1] + 2;
		if (chdir(vaguelette) == -1)
		{
			value = get_var_value((*tab)[is_exported(*tab, "PWD", 0)]);
			chdir(value);
			print_error("\033[1;91mminishell:\033[0;91m cd: ", temp[1],
				":\033[0m No such file or directory !\n");
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
		print_error("\033[1;91mminishell:\033[0;91m cd:\033[0m",
			" invalid option !\n", NULL);
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
		print_error("\033[1;91mminishell:\033[0;91m cd:\033[0m",
			" OLDPWD not set !\n", NULL);
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
