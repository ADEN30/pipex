/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:16:34 by agallet           #+#    #+#             */
/*   Updated: 2022/12/19 12:01:07 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str && str[i] && str[i] != c)
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_clear(char **str)
{
	if (str && *str)
	{	
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

int	right_side(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && *str && *str != '\n')
		str++;
	if (str && *str == '\n')
		str++;
	while (str && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	_str = NULL;
	while (s1 && s1[i] != '\n')
		i++;
	if (s1 && s1[i] == '\n')
		i++;
	_str = malloc(sizeof(char) * (ft_strlen(s1, '\0') - i + 1));
	if (!_str)
		return (NULL);
	while (s1 && s1[i])
	{
		_str[j] = s1[i];
		i++;
		j++;
	}
	_str[j] = '\0';
	return (_str);
}
