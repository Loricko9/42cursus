/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:14:10 by arthur            #+#    #+#             */
/*   Updated: 2024/02/03 15:17:29 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_bis(char ***tab, char **temp)
{
	if (temp[1][0] == '~')
		tilde_manage(tab, temp, is_exported(*tab, "HOME", 0));
	else if (temp[1][0] == '-')
		oldpwd_manage(tab, temp[1]);
	else if (chdir(temp[1]) == -1)
	{
		printf("\033[1;91mminishell:\033[0;91m cd: %s:\033[0m", temp[1]);
		printf(" No such file or directory !\n");
	}
	else
		update_pwd(tab);
}

void	ft_export_bis(char ***tab, char **temp, int i)
{
	char	*name;
	int		index;

	name = get_var_name(temp[i]);
	index = is_exported(*tab, name, 1);
	if (index == -1)
		*tab = add_index(*tab, temp[i]);
	else
		if (is_var_empty(temp[i]) != 2)
			*tab = mod_index(*tab, index, temp[i]);
}
