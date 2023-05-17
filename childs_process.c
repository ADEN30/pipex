/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:27:02 by agallet           #+#    #+#             */
/*   Updated: 2023/05/17 13:50:02 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_str2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

static	void	part_child1(t_pipe_t *piped, char **argv, char **envp)
{
	char	*error;

	error = NULL;
	if (!piped->access)
	{
		write(2, "pipex: ", 7);
		write(2, argv[2], ft_strlen(argv[2]));
		write(2, ": command not found\n", 20);
		exit(0);
	}
	parse_cmds(piped->cmds);
	if (dup2(piped->fd[0], STDIN_FILENO) == -1)
		exit(0);
	close(piped->fd[0]);
	if (dup2(piped->pip[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(0);
	}
	close(piped->pip[1]);
}

void	child1(t_pipe_t *piped, char **argv, char **envp)
{
	char	*error;

	error = NULL;
	if (piped->pid[0] == 0)
	{
		close(piped->pip[0]);
		close(piped->fd[1]);
		piped->cmds = ft_split(argv[2], ' ');
		del_ech(piped->cmds);
		join_sh(piped->cmds);
		access_path(piped, piped->cmds[0]);
		part_child1(piped, argv, envp);
		if (execve(piped->access, piped->cmds, envp) == -1)
		{
			perror((piped->cmds[0]));
			exit(127);
		}
	}
}

static	void	part_child2(t_pipe_t *piped, char **argv, char **envp)
{
	char	*error;

	error = NULL;
	if (!piped->access)
	{
		error = ft_strdup(argv[2]);
		error = ft_strjoin2(4, "pipex: ", argv[3], ": command not found", "\n");
		write(2, error, ft_strlen(error));
		exit(127);
	}
	parse_cmds(piped->cmds);
	if (dup2(piped->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(0);
	}
	if (dup2(piped->pip[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(0);
	}
	close(piped->pip[0]);
}

void	child2(t_pipe_t *piped, char **argv, char **envp)
{
	char	*error;

	error = NULL;
	if (piped->pid[1] == 0)
	{
		close(piped->pip[1]);
		piped->cmds = ft_split(argv[3], ' ');
		del_ech(piped->cmds);
		join_sh(piped->cmds);
		access_path(piped, piped->cmds[0]);
		part_child2(piped, argv, envp);
		if (execve(piped->access, piped->cmds, envp) == -1)
		{
			perror("execv");
			exit(127);
		}
	}
}
