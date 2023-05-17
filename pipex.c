/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:04:32 by agallet           #+#    #+#             */
/*   Updated: 2023/05/17 14:11:31 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_end(t_pipe_t *piped)
{
	close(piped->fd[0]);
	close(piped->fd[1]);
	close(piped->pip[0]);
	close(piped->pip[1]);
	waitpid(piped->pid[0], NULL, 0);
	waitpid(piped->pid[1], &(piped->status), 0);
}

int	check_fd(t_pipe_t *piped, char **argv)
{
	char	*error;

	piped->fd[0] = open(argv[1], O_RDONLY);
	piped->fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (piped->fd[0] == -1)
	{
		error = ft_strdup(argv[1]);
		error = ft_strjoin2(5, "pipex: ", argv[1], ": ", strerror(errno), "\n");
		write(2, error, ft_strlen(error));
	}
	if (piped->fd[1] == -1)
		exit(1);
	return (0);
}

static	int	end_pipex(t_pipe_t *piped, char **argv, char **envp)
{
	piped->pid[0] = fork();
	if (piped->pid[0] == -1)
	{
		ft_printf("Error fork\n");
		return (WEXITSTATUS(piped->status));
	}
	child1(piped, argv, envp);
	piped->access = NULL;
	piped->pid[1] = fork();
	child2(piped, argv, envp);
	ft_end(piped);
	return (WEXITSTATUS(piped->status));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_t	piped;

	piped.status = 0;
	pipe(piped.pip);
	if (argc != 5)
	{
		ft_printf("Error argument\n");
		ft_printf("errno : %d\n", errno);
		return (EXIT_FAILURE);
	}
	find_path(&piped, envp);
	if (!piped.paths && !ft_strnstr(argv[2], "./", 2)
		&& !ft_strnstr(argv[3], "./", 2))
	{
		ft_printf("1 exit\n");
		exit(5);
	}
	if (check_fd(&piped, argv))
		exit(127);
	return (end_pipex(&piped, argv, envp));
}
