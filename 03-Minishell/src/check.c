/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:24:40 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/31 11:24:40 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_redir(int *trig, int i, char *line)
{
	char	c;

	if (line[i] == '>' || line[i] == '<')
	{
		c = line[i];
		if (line[++i] == c)
			i++;
		if (line[i] == c)
		{
			*trig = 2;
			return ;
		}
		while (line[i] != '>' && line[i] != '<')
		{
			if (line[i] != ' ')
				return ;
			i++;
		}
		*trig = 2;
	}
}

void	ft_check_quote(int *trig, int *i, char *line)
{
	if (line[*i] == '"')
	{
		*trig = 1;
		++*i;
		while (line[*i] != '"' && line[*i] != '\0')
			++*i;
		if (line[*i] == '"')
			*trig = 0;
	}
	else if (line[*i] == '\'')
	{
		*trig = 1;
		++*i;
		while (line[*i] != '\'' && line[*i] != '\0')
			++*i;
		if (line[*i] == '\'')
			*trig = 0;
	}
}

int	ft_check_pipe2(char *line, int j)
{
	while (j >= 0 && line[j] != '|' && line[j] != '&')
	{
		if (line[j] != ' ')
			return (0);
		j--;
	}
	return (1);
}

int	ft_check_pipe(int i, char *line, int len)
{
	int	j;

	while (i < len)
	{
		j = i;
		if (line[i] == '|' || line[i] == '&')
			if (ft_check_pipe2(line, j - 1) == 1)
				return (1);
		i++;
	}
	return (ft_check_pipe2(line, j));
}

int	ft_check_line(char *line)
{
	int	i;
	int	trig;
	int	len;

	i = 0;
	trig = 0;
	len = ft_strlen(line);
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	i = -1;
	if (ft_check_pipe(i + 1, line, len) == 1)
		return (printf("\033[1;91mminishell:\033[0m"),
			printf(" syntaxe error near unexpected token !\n"), 2);
	while (++i < len)
	{
		ft_check_quote(&trig, &i, line);
		ft_check_redir(&trig, i, line);
		if (trig == 2)
			return (printf("\033[1;91mminishell:\033[0m syntaxe error !\n"), 2);
	}
	if (trig == 0)
		return (1);
	return (printf("\033[1;91mminishell:\033[0m undeterminated quote !\n"), 2);
}
