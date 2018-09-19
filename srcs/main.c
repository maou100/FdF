/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:18:43 by feedme            #+#    #+#             */
/*   Updated: 2018/08/29 18:15:03 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_fill_line(char *line, t_map *data, int i)
{
	int		j;
	int		k;
	int		j_save;
	char	*tmp;

	k = 0;
	j = 0;
	while (line[j])
	{
		if (line[j] == ' ')
			j++;
		else
		{
			j_save = j;
			while (line[j] && line[j] != ' ')
				j++;
			tmp = ft_strsub(line, j_save, j - j_save);
			data->z[i][k] = ft_atoi(tmp);
			free(tmp);
			k++;
		}
	}
}

static int	ft_get_coords(t_map *data, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	j = -1;
	while (++i < data->h)
	{
		if (get_next_line(fd, &line) == -1)
			ft_system_error("gnl");
		ft_fill_line(line, data, i);
		free(line);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_map	m;
	int		i;
	int		fd1;
	int		fd2;
	t_data	data;

	i = -1;
	if (ac != 2)
		ft_tiring_user("wrong_ac");
	if ((fd1 = open(av[1], O_RDONLY)) == -1 ||
			(fd2 = open(av[1], O_RDONLY)) == -1)
		ft_system_error("open");
	m = ft_check_map(fd1, -1, -1, 0);
	if (!(m.z = (int **)malloc(sizeof(int *) * m.h)))
		ft_system_error("malloc");
	while (++i < m.h)
		if (!(m.z[i] = (int *)malloc(sizeof(int) * m.w)))
			ft_system_error("malloc");
	if (ft_get_coords(&m, fd2) || close(fd1) == -1 || close(fd2) == -1)
		ft_system_error("close");
	data.ratio = (WIN_W / m.w > WIN_H / m.h ? WIN_H / m.h : WIN_W / m.w);
	ft_do_something(&data, &m);
	mlx_loop(data.mlx);
	return (0);
}
