/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:04 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/15 18:04:53 by tiacovel         ###   ########.fr       */
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
# define WIN_WIDTH	800
# define WIN_HEIGHT	800

# define MLX_ERROR	1
# define BACKGROUND_COLOR 0x000000
# define BASE_COLOR	"0xffffff"

typedef struct {
	int x, y;
} t_node_bi;

typedef struct {
	int x, y, z;
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
	t_node_bi		proj_coordinates;
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
int ft_hexstr_int(const char *hexstr);

int	handle_keyboard_input(int keysym, t_mlx_data *data);
int	handle_mouse_input(int keysym, t_mlx_data *data);
int handle_close_button(t_mlx_data *data);

void	color_pixel(t_mlx_data *data, int x, int y, int color);
void	color_background(t_mlx_data *data, int color);
void	plot_line(t_mlx_data *data, t_node_bi point_a, t_node_bi point_b);
void	draw_grid(t_mlx_data *data);

void	rotate(t_mlx_data *data, int rot_x, int rot_y, int rot_z);
void	zoom(t_mlx_data *data, int direction);
void	move(t_mlx_data *data, int tr_x, int tr_y);
void	destroy_window(t_mlx_data *data);

#endif