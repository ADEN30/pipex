/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:42:31 by agallet           #+#    #+#             */
/*   Updated: 2023/05/17 13:49:49 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_cmds(char **str)
{
	char	*tmp;
	int		i;
	int		parse;

	i = 1;
	parse = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((ft_strchr(str[i], '\"') || ft_strchr(&str[i][0], '\'')) && !parse)
			parse = i;
		else if (parse && str[i])
		{
			str[i] = join_space(str[i]);
			tmp = ft_strjoin(str[parse], str[i]);
			ft_clear(&str[parse]);
			ft_clear(&str[i]);
			str[parse] = tmp;
		}
		i++;
	}
	if (str[parse][0] == '\'' || str[parse][0] == '\"')
		delete_quote(str, tmp, parse);
	return (1);
}

void	del_ech(char **str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	while (str[i])
	{
		tab = ft_split(str[i], '\\');
		if (tab)
		{
			ft_clear(&str[i]);
			str[i] = ft_strjointab(tab);
			ft_clear(tab);
		}
		if (!ft_strchr3(str[i], '\\'))
			i++;
	}
}

int	find_sh(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strnstr(str[i], ".sh", ft_strlen(str[i])))
		{
			str[i] = &str[i][0];
			return (1);
		}
		str[i] = &str[i][0];
		i++;
	}
	return (0);
}

void	join_sh(char **str)
{
	char	*sh;
	int		i;

	i = 1;
	sh = NULL;
	if (!find_sh(str))
		return ;
	str[0] = &str[0][0];
	while (!ft_strnstr(str[0], ".sh", ft_strlen(str[0])) && str[i])
	{
		str[0] = &str[0][0];
		str[i] = ft_strjoin2(3, "\\", " ", str[i]);
		sh = ft_strjoin(str[0], str[i]);
		ft_clear(&str[0]);
		ft_clear(&str[i]);
		str[0] = sh;
		i++;
	}
	str[0] = &str[0][0];
}
