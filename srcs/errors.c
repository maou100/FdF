/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:55:14 by feedme            #+#    #+#             */
/*   Updated: 2018/08/06 10:31:07 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_tiring_user(char *str)
{
	if (!(ft_strcmp(str, "wrong_ac")))
		write(1, "fdf takes only 1 file as a parameter\n", 37);
	else if (!(ft_strcmp(str, "line_len")))
		write(1, "all lines need the same amount of number (z value)\n", 51);
	else if (!(ft_strcmp(str, "digitspace")))
		write(1, "the file can only contain spaces and numbers\n", 45);
	exit(0);
}

void	ft_system_error(char *str)
{
	if (ft_strcmp(str, "malloc"))
		write(1, "malloc failed\n", 14);
	else if (ft_strcmp(str, "open"))
		write(1, "open failed\n", 12);
	else if (ft_strcmp(str, "read"))
		write(1, "read failed\n", 12);
	else if (ft_strcmp(str, "close"))
		write(1, "close failed\n", 13);
	else if (ft_strcmp(str, "gnl"))
		write(1, "get_next_line failed\n", 21);
	else if (ft_strcmp(str, "mlx_init"))
		write(1, "failed to connect to mlx server\n", 32);
	exit(0);
}
