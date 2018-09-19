/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:22:59 by feedme            #+#    #+#             */
/*   Updated: 2018/08/18 12:05:53 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_ESCAPE			53
# define KEY_F1 			122
# define KEY_F2				120
# define KEY_F3				99
# define KEY_F4				118
# define KEY_F5				96
# define KEY_F6				97
# define KEY_F7				98
# define KEY_F8				100
# define KEY_F9				101
# define KEY_F10			109
# define KEY_F11			103
# define KEY_F12			111
# define KEY_F13			105
# define KEY_F14			107
# define KEY_F15			113
# define KEY_F16			106
# define KEY_F17			64
# define KEY_F18			79
# define KEY_F19			80
# define KEY_TILDE			50
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_0				29
# define KEY_MINUS			27
# define KEY_EQUAL			24
# define KEY_BACKSPACE		51
# define KEY_TAB			48
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_T				17
# define KEY_Y				16
# define KEY_U				32
# define KEY_I				34
# define KEY_O				31
# define KEY_P				35
# define KEY_OPEN_BRACKET	33
# define KEY_OPEN_BRACE		33
# define KEY_CLOSE_BRACKET	30
# define KEY_CLOSE_BRACE	30
# define KEY_BACKSLASH		42
# define KEY_PIPE			42
# define KEY_CAPSLOCK		272
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_COLON			41
# define KEY_SEMI_COLON		41
# define KEY_SIMPLE_QUOTE	39
# define KEY_DOUBLE_QUOTES	39
# define KEY_ENTER			36
# define KEY_SHIFT_LEFT		257
# define KEY_Z				6
# define KEY_X				7
# define KEY_C				8
# define KEY_V				9
# define KEY_B				11
# define KEY_N				45
# define KEY_M				46
# define KEY_LESS_THAN		43
# define KEY_COMMA			43
# define KEY_GREATER_THAN	47
# define KEY_DOT			47
# define KEY_SLASH			44
# define KEY_QUESTION_MARK	44
# define KEY_SHIFT_RIGHT	258
# define KEY_CTRL_LEFT		256
# define KEY_COMMAND_LEFT	259
# define KEY_OPTION_LEFT	261
# define KEY_ALT			261
# define KEY_SPACEBAR		49
# define KEY_COMMAND_RIGHT	260
# define KEY_ALT_GR			262
# define KEY_FN				279
# define KEY_CTRL_RIGHT		269
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DEL			117
# define KEY_HOME			115
# define KEY_END			119
# define KEY_PAGE_UP		116
# define KEY_PAGE_DOWN		121
# define KEY_CLEAR			71
# define KEY_PAD_1			83
# define KEY_PAD_2			84
# define KEY_PAD_3			85
# define KEY_PAD_4			86
# define KEY_PAD_5			87
# define KEY_PAD_6			88
# define KEY_PAD_7			89
# define KEY_PAD_8			91
# define KEY_PAD_9			92
# define KEY_PAD_0			82
# define KEY_PAD_EQUAL		81
# define KEY_PAD_DIVIDE		75
# define KEY_PAD_MULTIPLY	67
# define KEY_PAD_SUB		78
# define KEY_PAD_ADD		69
# define KEY_PAD_ENTER		76
# define KEY_PAD_DOT		65

# define WIN_W				1365
# define WIN_H				1024
# define IMG_W				WIN_W + 200
# define IMG_H				WIN_H + 200
# define COLOR				0x42bf50

# define X					(x + m->z[y][x] * d->x_ang / 150) * d->ratio
# define Y					(y + m->z[y][x] * d->y_ang / 150) * d->ratio
# define ISOX				X - Y
# define ISOY				(X + Y) / 2

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_bresenham
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				e;
	int				e2;
	int				range;
}					t_bresen;

typedef struct		s_map
{
	int				w;
	int				h;
	int				**z;
}					t_map;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_d;
	int				bpp;
	int				linesz;
	int				endian;
	int				projec;
	double			x0;
	double			y0;
	double			x_ang;
	double			y_ang;
	double			ratio;
	t_map			*m;
	int				booly;
}					t_data;

void				ft_interface(t_data *d, t_map *m);
int					keyboard(int key, void *param);
void				zoom(t_data *d);
void				dezoom(t_data *d);
void				ft_draw(t_data *d);
void				ft_erase(t_data *d);
int					ft_inb(t_point a);
int					mouse(int key, int x, int y, void *param);
int					ft_pixel_put(t_point a, t_data *d, int color);
void				ft_putline(t_data *d, t_point a, t_point b, int color);
void				ft_tiring_user(char *str);
void				ft_system_error(char *str);
int					get_next_line(int fd, char **line);
t_map				ft_check_map(int fd, int line_len, int tmp, int i);
void				ft_do_something(t_data *d, t_map *m);

#endif
