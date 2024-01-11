/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:19:45 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/09 18:19:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_prog(char **env, char *line)
{
	char	**cmd;
	char	*pwd;
	char	*path;
	int		res;

	res = 0;
	cmd = ft_split(line, ' ');
	if (!cmd)
		return(perror("minishell"), 1);
	pwd = getcwd(NULL, 1000);
	if (!pwd)
		return(perror("minishell"), ft_free_tab(cmd), 1);
	path = ft_strjoin(pwd, cmd[0] + 1);
	if (!path)
		return(perror("minishell"), ft_free_tab(cmd), free(pwd), 1);
	res = execve(path, cmd, env);
	if (res == -1)
		perror("minishell");
	free(pwd);
	free(path);
	ft_free_tab(cmd);
	exit(1);
}

void	ft_prog(char **env, char *line)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ft_exec_prog(env, line);
	else
		wait(NULL);
}

void	ft_case(char **env, char *line)
{
	if (ft_strcmp_shell(line, "./") == 1)
		ft_prog(env, line);
	else if (ft_strcmp_shell(line, "env") == 1)
		print_tab(env);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	
	(void)av;
	(void)ac;
	init_signal();
	while (1)
	{
		line = readline("minishell>");
		if (line == NULL || ft_strcmp_shell(line, "exit") == 1)
			break ;
		ft_case(env, line);
		add_history(line);
		free(line);
	}
	free(line);
}
