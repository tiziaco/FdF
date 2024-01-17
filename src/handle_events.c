/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:23:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/17 16:31:35 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_keyboard_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_q)
		rotate(data, 0, 0, -1);
	else if (keysym == XK_e)
		rotate(data, 0, 0, 1);
	else if (keysym == XK_w)
		rotate(data, -1, 0, 0);
	else if (keysym == XK_s)
		rotate(data, 1, 0, 0);
	else if (keysym == XK_a)
		rotate(data, 0, -1, 0);
	else if (keysym == XK_d)
		rotate(data, 0, 1, 0);
	else if (keysym == XK_Up)
		move(data, 0, -1);
	else if (keysym == XK_Down)
		move(data, 0, 1);
	else if (keysym == XK_Right)
		move(data, 1, 0);
	else if (keysym == XK_Left)
		move(data, -1, 0);
	else if (keysym == XK_plus)
		zoom(data, 1);
	else if (keysym == XK_minus)
		zoom(data, -1);
	else if (keysym == XK_Escape)
		destroy_window(data);
	ft_printf("The %d key has been pressed\n\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, 
							data->img.img_ptr, 200, 0);
	return (0);
}

int	handle_mouse_input(int keysym, t_mlx_data *data)
{
	(void)data;
	/* if (keysym == 4)
		zoom(data, -1);
	else if (keysym == 5)
		zoom(data, 1); */
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	handle_close_button(t_mlx_data *data)
{
	destroy_window(data);
	return (0);
}
