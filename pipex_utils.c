/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:56:03 by agallet           #+#    #+#             */
/*   Updated: 2023/05/17 14:05:11 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_space(char *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strjoin(" ", str);
	if (!tmp)
		return (NULL);
	free(str);
	return (tmp);
}

void	delete_quote(char **str, char *tmp, int parse)
{
	if (str[parse][0] == '\'')
		tmp = ft_strtrim(str[parse], "\'");
	else
		tmp = ft_strtrim(str[parse], "\"");
	ft_clear(&str[parse]);
	str[parse] = tmp;
}

char	*ft_strjoin2(int nb, ...)
{
	va_list	arg;
	char	*old;
	char	*new;
	char	*str;

	va_start(arg, nb);
	new = NULL;
	str = NULL;
	new = (char *)va_arg(arg, char *);
	old = (char *)va_arg(arg, char *);
	while (nb > 1)
	{
		new = ft_strjoin(new, old);
		ft_clear(&str);
		str = new;
		old = (char *)va_arg(arg, char *);
		nb--;
	}
	return (new);
}

char	*ft_strjointab(char **str)
{
	char	*new;
	int		i;

	i = 1;
	new = NULL;
	while (str[i])
	{
		new = ft_strjoin(str[0], str[i]);
		ft_clear(&str[0]);
		ft_clear(&str[i]);
		str[0] = new;
		i++;
	}
	new = ft_strdup(str[0]);
	ft_clear(&str[0]);
	return (new);
}

int	ft_strchr3(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{	
			return (1);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return (1);
	return (0);
}
