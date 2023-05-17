/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:26:52 by agallet           #+#    #+#             */
/*   Updated: 2023/04/04 12:23:12 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clearstruc(t_pipe_t *piped)
{
	ft_clear(piped->envp);
	ft_clear(piped->paths);
	ft_clear(&piped->access);
	ft_clear(piped->cmds);
}
