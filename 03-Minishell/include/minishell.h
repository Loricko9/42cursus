/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:20:11 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/05 11:36:41 by lle-saul         ###   ########.fr       */
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
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int	g_res_error;
extern int	g_res_sigint;

int		*get_redirec(char *str);
int		ft_case_change_env(char ***env, char *line);
void	ft_case(char **env, char *line, char **cmd);

/*check.c*/
void	ft_check_redir(int *trig, int i, char *line);
void	ft_check_quote(int *trig, int *i, char *line);
int		ft_check_pipe(int i, char *line, int len);
int		ft_check_line(char *line);

/*utils_signal.c*/
void	init_signal(void);
void	exec_signal_print(int signum);
void	recover_signal(void);
int		change_sigint(void);
void	exec_signal(int signum);

/*utils.c*/
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		ft_strcmp_shell(const char *s1, const char *s2, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_find_char_quote(const char *s1, const char c);

/*utils2.c*/
int		find_slash(char *line);
int		ft_tablen(char **tab);
char	**dup_tab(char **tab, int ac, char **av);
char	*ft_extract_str(char *str, int start, int end);
char	*ft_strjoin(char *s1, char *s2);

/*utils3.c*/
void	ft_free_tab(char **tab);
int		ft_strcmp(char *src, char *dest);
char	*ft_itoa(int n);
char	*print_start(void);

/*utils_fd.c*/
void	ft_redirect_fd(int fd_redir, int fd_to, int *fd);
int		*init_fd_tab(void);

/*print.c*/
void	print_tab(char **tab);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
void	ft_putstr_n(char *str, int fd);
void	print_error(char *str1, char *str2, char *str3);

/*exec.c*/
void	fork_exec(char ***env, char *line, int *fd);
char	*ft_clean_line(char *str);
int		ft_exec_prog(char **cmd, char **env, char *line);
int		ft_exec_cmd(char **cmd, char **env, char *line);

/*exec_utils.c*/
void	cmd_error(char *cmd);
char	*ft_clean_line2(char *str, int i);
int		ft_path_env(char **env, char *cmd);
void	ft_free_var(char **cmd, char **env_path, void *path, char **env);
char	*ft_get_path(char **path, char *cmd);

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
char	*change_line(char *line, char **env);
char	*new_line(char *line, char **env, int *i);
char	*get_var(char *line);
char	*create_new_line(char *var, char *line, char *env, int *index);

/*build_in.c*/
void	ft_pwd(void);
void	ft_echo(char *line);
void	ft_export(char ***tab, char *line);
void	ft_unset(char ***tab, char *line);
void	ft_cd(char ***tab, char **cmd);

/*build_in_utils.c*/
char	**rm_index(char **tab, int i);
char	**mod_index(char **tab, int i, char *str);
char	**add_index(char **tab, char *str);
int		is_exported(char **tab, char *str, int type);
int		ft_check_export(char *str);

/*build_in_bis.c*/
void	ft_env(char **env);
void	ft_export_bis(char ***tab, char **temp, int i);
void	ft_cd_bis(char ***tab, char **temp);

/*build_in_utils_bis.c*/
char	*get_var_name(char *line);
char	*get_var_value(char *line);
int		is_var_empty(char *line);
void	print_export(char **tab);

/*cd_utils*/
void	update_pwd(char ***tab);
void	tilde_manage(char ***tab, char **temp, int index);
void	old_pwd(char ***tab);
void	oldpwd_manage(char ***tab, char *line);
void	set_pwd(char ***tab);

#endif
