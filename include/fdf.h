/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:04 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/09 19:05:44 by tiacovel         ###   ########.fr       */
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

# define WIN_NAME	"Fdf - Display"
# define WIN_WIDTH	800
# define WIN_HEIGHT	800

# define MLX_ERROR	1

typedef struct	s_raw
{
	char			**data;
	struct s_raw	*next;
} t_raw;

typedef struct s_node 
{
	int				z;
	char			*color;
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
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
	t_raw	*map;
}	t_mlx_data;

t_raw	*new_raw(char **data);
void	add_raw(t_raw **raws, t_raw *new_node);
void	free_raws(t_raw *raws);
int		count_rows(t_raw *lst);

t_matrix	*construct_matrix(int m, int n);
void		free_matrix(t_matrix *matrix);

t_raw	*read_map(char *file_path);

int	handle_keyboard_input(int keysym, t_mlx_data *data);
int	handle_mouse_input(int keysym, t_mlx_data *data);
int handle_close_button(t_mlx_data *data);

void	color_pixel(t_mlx_data *data, int x, int y, int color);
void	color_background(t_mlx_data *data, int color);
void	plot_line(t_mlx_data *data, int x0, int y0, int x1, int y1);

#endif