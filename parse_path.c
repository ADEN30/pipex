/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:39:16 by agallet           #+#    #+#             */
/*   Updated: 2023/05/17 14:03:31 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path(t_pipe_t *piped, char **env)
{
	char	**tmp;
	int		i;
	int		length;

	tmp = env;
	i = 0;
	piped->paths = NULL;
	length = ft_strlen2d(env);
	while (i < length && ft_strncmp("PATH", tmp[i], 4))
		i++;
	if (i < length && !ft_strncmp("PATH", tmp[i], 4))
		piped->paths = ft_split(&tmp[i][5], ':');
}

static	int	build_path(t_pipe_t *piped, char *cmd)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (piped->paths && piped->paths[i])
	{
		if (piped->access)
		{
			ft_clear(&piped->access);
			piped->access = NULL;
		}
		tmp = ft_strjoin(piped->paths[i], "/");
		piped->access = ft_strjoin(tmp, cmd);
		ft_clear(&tmp);
		if (!access(piped->access, F_OK))
			return (1);
		i++;
	}
	return (0);
}

void	access_path(t_pipe_t *piped, char *cmd)
{
	if (build_path(piped, cmd))
		return ;
	ft_clear(&piped->access);
	if (!ft_strnstr(cmd, "./", 2) && !ft_strnstr(&cmd[0], "/", ft_strlen(cmd)))
		cmd = NULL;
	if (!access(cmd, X_OK))
	{
		piped->access = &cmd[0];
	}
	else if ((access(cmd, X_OK) && !access(cmd, F_OK)))
	{
		perror(cmd);
		exit(126);
	}
}
