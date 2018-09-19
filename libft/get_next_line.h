/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 19:08:15 by feedme            #+#    #+#             */
/*   Updated: 2018/08/18 19:08:39 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 42
# define IF_NULL_RZERO(a) if (!a) return (0);

typedef struct	s_gnl
{
	int				fd;
	char			*line;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
