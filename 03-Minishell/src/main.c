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

/*void	exec_pipe(int *fd, char **env, char *line, int nb_pipe)
{
	char	**cmd;
	int		i;
	int		nb_pipe_copy;

	nb_pipe_copy = nb_pipe;
	cmd = ft_extract_cmd(ft_split(line, "|"))
	if (fd[0] > -1)
		ft_redirect_fd_pipe(fd[0], STDIN_FILENO);
	while (--nb_pipe > 0)
		ft_case(env, cmd[i++]);
	if (fd[1] > -1)
		ft_redirect_fd_pipe(fd[1], STDOUT_FILENO);
	ft_case(env, cmd[i++]);
}

void	fork_pipe(int *fd, char **env, char *line, int nb_pipe)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("minishell");
	if (pid == 0)
		exec_pipe(fd, env, line, nb_pipe)
	else
		waitpid(pid, NULL, 0);
}

fd[0] = fd_in | fd[1] = fd_out
void	ft_pipe(char **env, char *line, int nb_pipe)
{
	char	trig;
	int		i;
	int		fd[2];

	fd[0] = -1;
	fd[1] = -1;
	i = 0;
	trig = 0;
	while (line[i] != '\0')
	{
		if (trig == 0 && (s1[i] == '"' || s1[i] == '\''))
			trig = s1[i];
		else if (trig > 0 && s1[i] == trig)
			trig = 0;
		if (line[i] == '<' && trig == 0)
			get_input(&fd[0], line + i + 1);
		else if (line[i] == '>' && trig == 0)
			get_output(&fd[1], line + i + 1);
		else if (line[i] == '|' && trig == 0)
			nb_pipe++;
		if (fd[0] == -2 || fd[1] == -2)
			return ;
		i++;
	}
	if (nb_pipe > 1)
		;
	else
		;
}*/

/*fd[0] = fd_in | fd[1] = fd_out*/
int	*get_redirec(char *str)
{
	char	trig;
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
		if (trig == 0 && (str[i] == '"' || str[i] == '\''))
			trig = str[i];
		else if (trig > 0 && str[i] == trig)
			trig = 0;
		if (str[i] == '<' && trig == 0)
			get_input(&fd[0], str + i + 1);
		else if (str[i] == '>' && trig == 0)
			get_output(&fd[1], str + i + 1);
		if (fd[0] == -2 || fd[1] == -2)
			return (fd);
	}
	return (fd);
}

void ft_case(char **env, char *line, void (*ft)(char **, char *, int (*fonction)(char **, char **), int *fd))
{
	if (ft_find_char_quote(line, '|') == 1)
		ft_pipe(env, ft_split(line, "|"));
	else
	{
		if (ft_strcmp_shell(line, "./") == 1)
			ft(env, line, ft_exec_prog, get_redirec(line));
		else if (ft_strcmp_shell(line, "env") == 1)
			print_tab(env);
		else
			ft(env, line, ft_exec_cmd, get_redirec(line));
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**my_env;
	
	(void)av;
	(void)ac;
	my_env = dup_tab(env);
	if (!my_env)
		return (printf("Error : malloc\n"));
	//init_signal();
	while (1)
	{
		line = readline("minishell>");
		if (line == NULL || ft_strcmp_shell(line, "exit") == 1)
			break ;
		if (ft_check_quote(line) == 1)
			ft_case(my_env, line, fork_exec);
		add_history(line);
		free(line);
	}
	free(line);
	ft_free_tab(my_env);
}
	