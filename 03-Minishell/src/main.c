/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:19:45 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/22 16:51:09 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		res_error;

void	ft_redirect_fd(int fd_redir, int fd_to, int *fd)
{
	if (dup2(fd_redir, fd_to) == -1)
	{
		perror("minishell");
		if (fd)
			free(fd);
		exit(1);
	}
}

/*fd[0] = fd_in | fd[1] = fd_out*/
int	*get_redirec(char *str)
{
	int	trig;
	int		*fd;
	int		i;

	fd = malloc(sizeof(int) * 2);
	if (!fd)
		return (NULL);
	fd[0] = -1;
	fd[1] = -1;
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
		if (fd[0] == -2 || fd[1] == -2)
			return (fd);
	}
	return (fd);
}

/*void	ft_case(char **env, char *line, void (*ft)(char **, char *, int (*fonction)(char **, char **), int *fd), int *fd)
{
	if (ft_strcmp_shell(line, "./", 1) == 1)
		ft(env, line, ft_exec_prog, fd);
	else if (ft_strcmp_shell(line, "env", 0) == 1)
		print_tab(env);
	else if (ft_strcmp_shell(line, "pwd", 0) == 1)
		ft_pwd(env);
	else if (ft_strcmp_shell(line, "echo", 0) == 1)
		ft_echo(line);
	else if (ft_strcmp_shell(line, "export", 0) == 1)
		ft_export(env, line);
	else
		ft(env, line, ft_exec_cmd, fd);
}*/

void	ft_case(char **env, char *line)
{
	line = ft_clean_line(line);
	if (ft_strcmp_shell(line, "./", 1) == 1)
		exit(ft_exec_prog(ft_split(line, " ", 0), env));
	else if (ft_strcmp_shell(line, "env", 0) == 1)
	{
		print_tab(env);
		exit(1);
	}
	else if (ft_strcmp_shell(line, "pwd", 0) == 1)
		ft_pwd(env);
	else if (ft_strcmp_shell(line, "echo", 0) == 1)
		ft_echo(line);
	else
		exit(ft_exec_cmd(ft_split(line, " ", 0), env));
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**my_env;


	my_env = dup_tab(env, ac, av);
	if (!my_env)
		return (printf("Error : malloc\n"));
	init_signal();
	while (1)
	{
		line = readline("\033[32mminishell> \033[0m");
		add_history(line);
		line = check_var(line, env);
		if (line == NULL || ft_strcmp_shell(line, "exit", 0) == 1)
			break ;
		else if (ft_check_line(line) == 1)
		{
			if (ft_find_char_quote(line, '|') == 1)
				ft_pipe(env, ft_split(line, "|", 1));
			else
				fork_exec(env, line, NULL);
		}
		free(line);
	}
	return (free(line), ft_free_tab(my_env), 1);
}
