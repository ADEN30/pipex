/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:57:32 by agallet           #+#    #+#             */
/*   Updated: 2023/03/15 13:03:39 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

int		ft_strchr2(const char *s, int c);

int		ft_strlen2(char *str, char c);

char	*ft_clear(char **str);

int		right_side(char *str);

char	*ft_strdup2(char *s1);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
