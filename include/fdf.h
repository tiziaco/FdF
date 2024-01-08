/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:04 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/08 18:12:53 by tiacovel         ###   ########.fr       */
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

# define MLX_ERROR	1
# define WIN_WIDTH	400
# define WIN_HEIGHT	400

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

typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
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

#endif