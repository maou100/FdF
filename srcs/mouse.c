/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:20:39 by feedme            #+#    #+#             */
/*   Updated: 2018/08/18 19:24:31 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_interface(t_data *d, t_map *m)
{
	char	*str;

	str = ft_itoa(m->w);
	mlx_string_put(d->mlx, d->win, 10, 10, 0xff0000, "Width");
	mlx_string_put(d->mlx, d->win, 88, 10, 0xffff00, str);
	free(str);
	str = ft_itoa(m->h);
	mlx_string_put(d->mlx, d->win, 10, 30, 0xff0000, "Heigth");
	mlx_string_put(d->mlx, d->win, 88, 30, 0xffff00, str);
	free(str);
}

void	zoom(t_data *d)
{
	d->ratio += 2;
	if (d->ratio > 100)
		d->ratio += 3;
}

void	dezoom(t_data *d)
{
	if (d->ratio > 1)
	{
		d->ratio -= 2;
		if (d->ratio > 100)
			d->ratio -= 3;
	}
}

int		mouse(int key, int x, int y, void *param)
{
	t_data	*d;

	x = 4;
	y = 2;
	d = param;
	ft_erase(d);
	if (key == 5)
		zoom(d);
	else if (key == 4)
		dezoom(d);
	ft_draw(d);
	return (0);
}
