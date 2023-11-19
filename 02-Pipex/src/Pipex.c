/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:27:18 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/17 17:27:18 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_exec_cmd(char **cmd, char **env)
{
	char	*path;
	char	**env_path;
	int		res;

	res = 0;
	env_path = ft_split(env[3], ':');
	if (!env_path)
	{
		perror("malloc");
		ft_free_tab(cmd);
		exit(1);
	}
	path = ft_get_path(env_path, cmd[0]);
	res = execve(path, cmd, env);
	ft_free_var(cmd, env_path, path);
	if (res == -1)
	{
		perror("execve");
		exit(1);
	}
}

int	ft_redirect_fd(char	*file1, char *file2)
{
	int	fd1;
	int	fd2;
	
	fd1 = open(file1, O_RDWR);
	if (fd1 < 0)
		return (perror("open"), 1);
	if (dup2(fd1, STDIN_FILENO) == -1)
		return (perror("dup2"), 1);
	close(fd1);
	fd2 = open(file2, O_RDWR | O_CREAT, 00777);
	if (fd2 < 0)
		return (perror("open"), 1);
	return (0);
}

/*fd[0] = read | fd[1] = write*/
int	ft_pid_create(char **av, int pid_nb, int j, char **env)
{
	int	fd[2];
	int	pid;
	int	j;

	j = 2;
	if (pipe(fd) == -1)
		return (perror("pipe"), 1);
	while (pid_nb > 0)
	{
		pid = fork();
		if (pid == -1)
			return (perror("fork"), 1);
		if (pid == 0)
			ft_exec_cmd(ft_split(av[j], ' '), env);
	
		pid_nb--;
		j++;
	}
	return (0);
}
//couper le programme parent quand l'enfant echoue	
int	main(int ac, char **av, char **env)
{
	(void)env;
	if (ac < 5)
		return (1);
	if (ft_redirect_fd(av[1], av[ac - 1]) == 1)
		return (1);
	if (ft_pid_create(av, ac - 4, 2, env) == -1)
		return (1);
}
