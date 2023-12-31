/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:23:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/09 19:09:06 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_keyboard_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_r)
		color_background(data, 0xff0000);
	else if (keysym == XK_d)
		plot_line(data, 200, 200, 500, 500);
	else if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_raws(data->map);
		exit (EXIT_SUCCESS);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, 
							data->img.img_ptr, 0, 0);
	return (0);
}

int	handle_mouse_input(int keysym, t_mlx_data *data)
{
	(void)data;
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	handle_close_button(t_mlx_data *data)
{
	ft_printf("The close button has been pressed\n\n");
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_raws(data->map);
	exit (EXIT_SUCCESS);
	return (0);
}
