/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:44:12 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/25 14:59:11 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define GNL_BUFF_SIZE 256
# define R rl->buf

# include "../libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_list	t_list;

struct	s_list
{
	int			ret;
	char		*buf;
	int			cpd;
};

extern char		*g_builtin[];

char	*home_path(char **envp);
char	*old_path(char **envp);
char	*cut_strchr(char *str, int c);
int		str_index(char **envp, char *cmp);
void	print_currpath(void);
int		sys_fork(char *path, char **argv, char **envp);
int		ft_setenv(char *str, char ***envp);
void	sys_cmd(char **argv, char **envp);
void	call_builtin(char **argv, char ***envp);
int		get_next_line(const int fd, char **line);
char	**ft_split_whitespaces(char *str);
void	ft_env(char **argv, char **envp);
void	ft_lst_unsetenv(char **argv, char ***envp);
int		ft_lst_setenv(char **argv, char ***envp);
void	ft_exit(void);
int		ft_cd(char *path, char ***envp);
void	ft_echo(char **argv);

#endif
