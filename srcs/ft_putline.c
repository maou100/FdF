/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:45:14 by feedme            #+#    #+#             */
/*   Updated: 2018/08/31 13:12:56 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_pixel_put(t_point a, t_data *d, int color)
{
	int			i;

	if (ft_inb(a))
	{
		i = a.x * (d->bpp / 8) + a.y * d->linesz;
		d->img_d[i] = color;
		d->img_d[++i] = color >> 8 & 0xff;
		d->img_d[++i] = color >> 16;
	}
	return (1);
}

void	ft_vars(t_point a, t_point b, t_bresen *var)
{
	var->dx = abs(b.x - a.x);
	var->sx = a.x < b.x ? 1 : -1;
	var->dy = abs(b.y - a.y);
	var->sy = a.y < b.y ? 1 : -1;
	var->e = (var->dx > var->dy ? var->dx : -var->dy) / 2;
	var->e2 = var->e;
	if (var->dy != 0)
		var->range = 200 / var->dy;
}

void	ft_troplong(t_bresen *var, t_point *a, t_data *d, int *color)
{
	var->e += var->dx;
	a->y += var->sy;
	if (d->booly)
		*color += var->range;
	else
	{
		if (*color)
			*color += var->range;
	}
}

void	ft_putline(t_data *d, t_point a, t_point b, int color)
{
	t_bresen	var;

	ft_vars(a, b, &var);
	while (42)
	{
		ft_pixel_put(a, d, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		var.e2 = var.e;
		if (var.e2 > -var.dx)
		{
			var.e -= var.dy;
			a.x += var.sx;
		}
		if (var.e2 < var.dy)
			ft_troplong(&var, &a, d, &color);
	}
}
