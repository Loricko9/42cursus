/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:14:10 by arthur            #+#    #+#             */
/*   Updated: 2024/02/04 19:41:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **env)
{
	int	j;
	int	i;

	j = 0;
	while (env[j] != NULL)
	{
		i = 0;
		while (env[j][i] != '\0' && env[j][i] != '=')
			i++;
		if (env[j][i] != '\0')
			printf("%s\n", env[j]);
		j++;
	}
}

void	ft_cd_bis(char ***tab, char **temp)
{
	if (temp[1][0] == '~')
		tilde_manage(tab, temp, is_exported(*tab, "HOME", 0));
	else if (temp[1][0] == '-')
		oldpwd_manage(tab, temp[1]);
	else if (chdir(temp[1]) == -1)
	{
		print_error("\033[1;91mminishell:\033[0;91m cd: ", temp[1], NULL);
		ft_putstr(":\033[0m No such file or directory !\n", 2);
		g_res_error = 1;
		return ;
	}
	else
		update_pwd(tab);
	g_res_error = 0;
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
