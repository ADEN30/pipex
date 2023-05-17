/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:25:08 by agallet           #+#    #+#             */
/*   Updated: 2023/05/17 14:14:39 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct t_pipe
{
	int		fd[2];
	int		pip[2];
	int		pid[2];
	int		status;
	char	**envp;
	char	**paths;
	char	*access;
	char	**cmds;
}	t_pipe_t;

int		parse_cmds(char **str);
void	access_path(t_pipe_t *piped, char *cmd);

/* child_process */
void	child1(t_pipe_t *piped, char **argv, char **envp);
void	child2(t_pipe_t *piped, char **argv, char **envp);
void	put_str2d(char **str);

/* parse_path */
void	find_path(t_pipe_t *piped, char **env);
void	access_path(t_pipe_t *piped, char *cmd);

/* parse_cmds */
int		parse_cmds(char **str);
void	join_sh(char **str);
void	del_ech(char **str);

/* pipex_utils */
char	*join_space(char *str);
char	*ft_strjoin2(int nb, ...);
char	*ft_strjointab(char **str);
void	delete_quote(char **str, char *tmp, int parse);
int		ft_strchr3(const char *s, int c);

/* pipex_utils2 */
void	ft_clearstruc(t_pipe_t *piped);

#endif
