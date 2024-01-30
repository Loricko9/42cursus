/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:20:11 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/09 18:20:11 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

extern	int res_error;

int		*get_redirec(char *str);
void	ft_case(char **env, char *line);
void	ft_redirect_fd(int fd_redir, int fd_to, int *fd);;

/*utils.c*/
void	init_signal(void);
void	exec_signal(int signum);
int		ft_strcmp_shell(const char *s1, const char *s2, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_find_char_quote(const char *s1, const char c);

/*utils2.c*/
int		ft_tablen(char **tab);
char	**dup_tab(char **tab, int ac, char **av);
int		ft_check_line(char *line);
char	*ft_extract_str(char *str, int start, int end);

/*utils3.c*/
void	ft_free_tab(char **tab);
void	ft_check_redir(int *trig, int i, char *line);
int		ft_strcmp(char *src, char *dest);
char	*ft_itoa(int n);

/*utils4.c*/
int		ft_strlen(char *str);
char	*ft_strdup(char *s);

/*print.c*/
void	print_tab(char **tab);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
void	ft_putstr_n(char *str, int fd);

/*exec.c*/
void	fork_exec(char **env, char *line, int *fd);
char	*ft_clean_line(char *str);
int		ft_exec_prog(char **cmd, char **env);
int		ft_exec_cmd(char **cmd, char **env);

/*exec_utils.c*/
char	*ft_clean_line2(char *str, int i);
int		ft_path_env(char **env);
void	ft_free_var(char **cmd, char **env_path, char *path);
char	*ft_get_path(char **path, char *cmd);
char	*ft_strjoin(char *s1, char *s2);

/*exec_pipe.c*/
void	redirect_fd_pipe(int *fd_pipe, int *fd, int i);
void	ft_pipe(char **env, char **cmd);

/*get_fd.c*/
int		get_len_quote(char *str);
void	get_input(int *fd_in, char *line);
void	get_output(int *fd_out, char *line);
void	get_output_append(int *fd_out, char *line, int *j);

/*get_fd_heredoc.c*/
char	*ft_malloc_path_fd(char *str, int len);
char	*extract_path_fd(char *str);
void	get_input_heredoc(int *fd_in, char *line, int *fd, int *j);

/*ft_split.c*/
void	ft_cote(int *val, char c);
char	**ft_split(char *s, char *c, int bol_quote);
int		ft_find_char(const char *s1, const char c);

/*check_var_env.c*/
char	*check_var(char *line, char **env);
char	*new_line(char *line, char **env, int *i);
char	*get_var(char *line);
char	*create_new_line(char *var, char *line, char *env, int *index);

/*build_in.c*/
void	ft_pwd(char **tab);
void	ft_echo(char *line);
void	ft_export(char ***tab, char *line);
void	print_export(char **tab);

/*build_in_utils.c*/
char	**rm_index(char **tab, int i);
char	**mod_index(char **tab, int i, char *str);
char	**add_index(char **tab, char *str);
int		is_exported(char **tab, char *str);

/*build_in_utils_bis.c*/
char	*get_var_name(char *line);

#endif

