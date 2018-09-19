/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 21:46:11 by feedme            #+#    #+#             */
/*   Updated: 2018/08/18 19:12:10 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_digits_spaces(char *line)
{
	int		i;
	int		rien;

	i = -1;
	while (line[++i])
	{
		if ((line[i] >= '0' && line[i] <= '9') ||
			line[i] == ' ' || line[i] == '-')
			rien = 42;
		else
			return (0);
	}
	return (1);
}

static int		ft_parse_line(char *line)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!(ft_digits_spaces(line)))
		ft_tiring_user("digitspace");
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
		{
			count++;
			while (line[i] && line[i] != ' ')
				i++;
		}
	}
	return (count);
}

t_map			ft_check_map(int fd, int line_len, int tmp, int i)
{
	char	*line;
	int		gnl_ret;
	t_map	map_data;

	while ((gnl_ret = get_next_line(fd, &line)) > 0)
	{
		tmp = line_len;
		line_len = ft_parse_line(line);
		if (tmp != -1)
			if (tmp != line_len)
				ft_tiring_user("line_len");
		i++;
		free(line);
	}
	if (gnl_ret == -1)
		ft_system_error("gnl");
	map_data.h = i;
	map_data.w = line_len;
	return (map_data);
}
