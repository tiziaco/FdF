/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:04 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/02 13:25:22 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/gnl/get_next_line.h"
#include <math.h>
#include <fcntl.h>
#include <mlx.h>
#include <X11/keysym.h>

#define MLX_ERROR	1
#define WIN_WIDTH	400
#define WIN_HEIGHT	400

typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_mlx_data;