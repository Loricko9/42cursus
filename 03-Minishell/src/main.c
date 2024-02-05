/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:19:45 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/05 13:14:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_res_error;
int		g_res_sigint;

/*fd[0] = fd_in | fd[1] = fd_out*/
int	*get_redirec(char *str)
{
	int	trig;
	int	*fd;
	int	i;

	fd = init_fd_tab();
	if (!fd)
		return (NULL);
	i = -1;
	trig = 0;
	while (str[++i] != '\0')
	{
		ft_cote(&trig, str[i]);
		if (str[i] == '<' && str[i + 1] == '<' && trig == 0)
			get_input_heredoc(&fd[0], str + i + 2, fd, &i);
		else if (str[i] == '<' && trig == 0)
			get_input(&fd[0], str + i + 1);
		else if (str[i] == '>' && str[i + 1] == '>' && trig == 0)
			get_output_append(&fd[1], str + i + 2, &i);
		else if (str[i] == '>' && trig == 0)
			get_output(&fd[1], str + i + 1);
		if (fd[0] == -1 || fd[1] == -1)
			return (fd);
	}
	return (fd);
}

int	ft_case_change_env(char ***env, char *line)
{
	if (ft_strcmp_shell(line, "export", 0) == 1)
		ft_export(env, line);
	else if (ft_strcmp_shell(line, "unset", 0) == 1)
		ft_unset(env, line);
	else if (ft_strcmp_shell(line, "cd", 0) == 1)
		ft_cd(env, ft_split(line, " ", 0));
	else
		return (1);
	return (0);
}

void	ft_case(char **env, char *line, char **cmd)
{
	line = ft_clean_line(line);
	if (find_slash(line) == 1)
		exit(ft_exec_prog(ft_split(line, " ", 0), env, line));
	else if (ft_strcmp_shell(line, "env", 0) == 1)
		ft_env(env);
	else if (ft_strcmp_shell(line, "pwd", 0) == 1)
		ft_pwd();
	else if (ft_strcmp_shell(line, "echo", 0) == 1)
		ft_echo(line);
	else if (ft_strcmp_shell(line, "export", 0) == 1 || ft_strcmp_shell(line,
			"unset", 0) == 1 || ft_strcmp_shell(line, "cd", 0) == 1
		|| ft_strcmp_shell(line, "exit", 0) == 1)
		line = line;
	else
		exit(ft_exec_cmd(ft_split(line, " ", 0), env, line));
	ft_free_tab(env);
	if (cmd)
		ft_free_tab(cmd);
	free(line);
	exit(0);
}

int	exploit_line(char *line, char ***my_env)
{
	if (line)
		add_history(line);
	line = change_line(line, *my_env);
	if (line == NULL)
		return (1);
	g_res_sigint = 0;
	if (ft_check_line(line) == 1 && change_sigint() == 1)
	{
		if (ft_find_char_quote(line, '|') == 1)
			ft_pipe(*my_env, ft_split(line, "|", 1));
		else if (ft_strcmp_shell(line, "exit", 0) == 1)
			return (1);
		else
			fork_exec(my_env, line, NULL);
	}
	free(line);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**my_env;
	int		std_in;
	char	*prompt;

	my_env = dup_tab(env, ac, av);
	if (!my_env)
		return (printf("\033[2;91mFatal Error:\033[0m malloc !\n"));
	std_in = dup(STDIN_FILENO);
	while (1)
	{
		std_in = dup(STDIN_FILENO);
		init_signal();
		prompt = print_start();
		line = readline(prompt);
		free(prompt);
		if (line == NULL && g_res_sigint == 1)
		{
			dup2(std_in, STDIN_FILENO);
			continue ;
		}
		if (exploit_line(line, &my_env) == 1)
			break ;
	}
	return (rl_clear_history(), free(line), ft_free_tab(my_env), 1);
}
