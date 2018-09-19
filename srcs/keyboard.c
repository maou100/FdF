/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:14:22 by feedme            #+#    #+#             */
/*   Updated: 2018/08/23 19:50:29 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, IMG_W, IMG_H);
	d->ratio = (WIN_W / d->m->w > WIN_H / d->m->h ?
		WIN_H / d->m->h : WIN_W / d->m->w);
	d->x0 = 100;
	d->y0 = 100;
	d->x_ang = 0;
	d->y_ang = 0;
}

void	translate(t_data *d, int key)
{
	if (key == KEY_LEFT)
		d->x0 -= 20;
	if (key == KEY_RIGHT)
		d->x0 += 20;
	if (key == KEY_DOWN)
		d->y0 += 20;
	if (key == KEY_UP)
		d->y0 -= 20;
}

void	angle(t_data *d, int key)
{
	if (key == KEY_W)
		d->y_ang -= 1;
	if (key == KEY_S)
		d->y_ang += 1;
	if (key == KEY_A)
		d->x_ang -= 1;
	if (key == KEY_D)
		d->x_ang += 1;
	if (key == KEY_1)
		d->projec = 1;
	if (key == KEY_2)
		d->projec = 2;
}

int		keyboard(int key, void *param)
{
	t_data *d;

	d = param;
	ft_erase(d);
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_image(d->mlx, d->img);
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	else if (key >= 123 && key <= 126)
		translate(d, key);
	else if ((key >= 0 && key <= 2) || key == 13 || key == 18 || key == 19)
		angle(d, key);
	else if (key == KEY_PAD_ADD)
		zoom(d);
	else if (key == KEY_PAD_SUB)
		dezoom(d);
	else if (key == KEY_DEL)
		reset(d);
	else if (key == KEY_F)
		d->booly = d->booly == 0 ? 1 : 0;
	ft_draw(d);
	return (0);
}
