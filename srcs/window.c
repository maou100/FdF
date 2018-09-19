/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 01:47:30 by feedme            #+#    #+#             */
/*   Updated: 2018/08/18 19:13:45 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_inb(t_point a)
{
	if (a.x >= IMG_W || a.y >= IMG_H || a.x < 0 || a.y < 0)
		return (0);
	return (1);
}

t_point		ft_transfo(int x, int y, t_data *d, t_map *m)
{
	t_point	a;

	if (d->projec == 1)
		a = (t_point){d->x0 + X, d->y0 + Y};
	else
		a = (t_point){d->x0 + ISOX, d->y0 + ISOY};
	return (a);
}

void		ft_erase(t_data *d)
{
	t_point a;
	int		x;
	int		y;

	y = -1;
	while (++y < d->m->h && (x = -1))
		while (++x < d->m->w)
		{
			a = ft_transfo(x, y, d, d->m);
			if (ft_inb(a))
			{
				ft_pixel_put(a, d, 0);
				if (x + 1 < d->m->w && ft_inb(ft_transfo(x + 1, y, d, d->m)))
					ft_putline(d, a, ft_transfo(x + 1, y, d, d->m), 0);
				if (y + 1 < d->m->h && ft_inb(ft_transfo(x, y + 1, d, d->m)))
					ft_putline(d, a, ft_transfo(x, y + 1, d, d->m), 0);
			}
		}
}

void		ft_draw(t_data *d)
{
	t_point a;
	int		x;
	int		y;

	y = -1;
	while (++y < d->m->h && (x = -1))
		while (++x < d->m->w)
		{
			a = ft_transfo(x, y, d, d->m);
			if (ft_inb(a))
			{
				ft_pixel_put(a, d, COLOR);
				if (x + 1 < d->m->w && ft_inb(ft_transfo(x + 1, y, d, d->m)))
					ft_putline(d, a, ft_transfo(x + 1, y, d, d->m), COLOR);
				if (y + 1 < d->m->h && ft_inb(ft_transfo(x, y + 1, d, d->m)))
					ft_putline(d, a, ft_transfo(x, y + 1, d, d->m), COLOR);
			}
		}
	mlx_put_image_to_window(d->mlx, d->win, d->img, -50, -50);
	ft_interface(d, d->m);
}

void		ft_do_something(t_data *d, t_map *m)
{
	d->projec = 1;
	d->booly = 0;
	d->x_ang = -2;
	d->y_ang = -2;
	d->x0 = 100;
	d->y0 = 100;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_W, WIN_H, "FdF");
	d->img = mlx_new_image(d->mlx, IMG_W, IMG_H);
	d->img_d = mlx_get_data_addr(d->img, &(d->bpp), &(d->linesz), &(d->endian));
	d->m = m;
	mlx_hook(d->win, 2, 3, keyboard, d);
	mlx_mouse_hook(d->win, mouse, d);
	ft_draw(d);
}
