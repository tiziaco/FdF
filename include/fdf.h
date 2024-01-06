/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:04 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/06 13:13:26 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <X11/keysym.h>

# define MLX_ERROR	1
# define WIN_WIDTH	400
# define WIN_HEIGHT	400

typedef struct s_node 
{
	int				z;
	struct s_node	*right;
	struct s_node	*down;
} t_matrix;

typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_mlx_data;

t_matrix	*construct_matrix(int **mat, int m, int n);
void		free_matrix(t_matrix *matrix);

#endif