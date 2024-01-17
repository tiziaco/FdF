/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:04 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/17 17:02:59 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "../include/libft.h"

#include <stdio.h> // Da togliere!!

# define WIN_NAME	"Fdf - Display"
# define WIN_WIDTH	1000
# define WIN_HEIGHT	600

# define IMG_WIDTH	800
# define IMG_HEIGHT	600

# define MLX_ERROR	1

# define BACKGROUND_COLOR	0x202020
# define BASE_COLOR			"0x4141FF"
# define BASE_COLOR_UP		"0x39FF36"
# define BASE_COLOR_DOWN	"0xE136FF"
# define TEXT_COLOR			0xffffff

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
} t_color;

typedef struct	s_node_bi
{
	int	x;
	int	y;
} t_node_bi;

typedef struct	s_node_tri
{
	int x;
	int y;
	int z;
} t_node_tri;

typedef struct s_view
{
	int	rot_x;
	int	rot_y;
	int	rot_z;
	int	zoom;
} t_view;

typedef struct s_origin
{
	int	x0;
	int	y0;
} t_origin;

typedef struct	s_raw
{
	char			**data;
	struct s_raw	*next;
} t_raw;

typedef struct	s_node
{
	int				x;
	int				y;
	int				z;
	t_node_bi		pj_cor;
	int				color;
	struct s_node	*right;
	struct s_node	*down;
} t_matrix;

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
} t_img;

typedef struct	data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	t_matrix	*map;
	t_view		view;
	t_origin	origin;
}	t_mlx_data;

t_raw	*new_raw(char **data);
void	add_raw(t_raw **raws, t_raw *new_node);
void	free_raws(t_raw *raws);
int		count_rows(t_raw *lst);

t_matrix	*convert_raws_to_matrix(char *file_path);
void		free_matrix(t_matrix *matrix);
void		free_split(char **data);
void		transform_nodes(t_matrix *matrix, t_view view, t_origin origin);

t_raw	*read_map(char *file_path);
int		ft_hexstr_int(const char *hexstr);

int		handle_keyboard_input(int keysym, t_mlx_data *data);
int		handle_mouse_input(int keysym, t_mlx_data *data);
int		handle_close_button(t_mlx_data *data);

int		get_color(t_matrix *p1, t_matrix *p2, t_node_bi	cur);
void	color_pixel(t_mlx_data *data, int x, int y, int color);
void	color_background(t_mlx_data *data, int color);
void	plot_line(t_mlx_data *data, t_matrix *p1, t_matrix *p2);
void	draw_grid(t_mlx_data *data);

void	rotate(t_mlx_data *data, int rot_x, int rot_y, int rot_z);
void	zoom(t_mlx_data *data, int direction);
void	move(t_mlx_data *data, int tr_x, int tr_y);
void	destroy_window(t_mlx_data *data);

#endif