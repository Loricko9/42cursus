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

void	ft_pipe(char **env, char *line, int nb_pipe)
{
	int		fd_in;
	int		fd_out;
	int		i;

	fd_in = -1;
	fd_out = -1;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' && fd_in == -1)
			get_input(&fd_in, line + i + 1);
		else if (line[i] == '>' && fd_out == -1)
			get_output(&fd_in, line + i + 1);
		else if (line[i] == '|')
			nb_pipe++;
		if (fd_in == -2 || fd_out == -2)
			return ;
		i++;
	}
	if (nb_pipe > 1)
		;
	else
		;
}

void	ft_case(char **env, char *line)
{
	if (ft_find_char(line, '|') == 1 || ft_find_char(line, '<') == 1 || ft_find_char(line, '>') == 1)
		ft_pipe(env, line, 1);
	else if (ft_strcmp_shell(line, "./") == 1)
		fork_exec(env, line, ft_exec_prog);
	else if (ft_strcmp_shell(line, "env") == 1)
		print_tab(env);
	else
		fork_exec(env, line, ft_exec_cmd);
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
			ft_case(my_env, line);
		add_history(line);
		free(line);
	}
	free(line);
	ft_free_tab(my_env);
}
