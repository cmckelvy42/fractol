/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normsucks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:48:10 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/07/05 22:10:33 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	print_help(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF,
		"1-4: Change Colors (2-4 are Psychedelic Mode)");
	mlx_string_put(mlx->mlx, mlx->window, 10, 25, 0xFFFFFF,
		"Mouse1/Mouse2/Scrollwheel: Zoom in or out");
	mlx_string_put(mlx->mlx, mlx->window, 10, 40, 0xFFFFFF,
		"Space: Reset");
	mlx_string_put(mlx->mlx, mlx->window, 10, 55, 0xFFFFFF,
		"Arrows: Move");
	mlx_string_put(mlx->mlx, mlx->window, 10, 70, 0xFFFFFF,
		"+/-: Iterate/Deiterate");
	mlx_string_put(mlx->mlx, mlx->window, 10, 85, 0xFFFFFF,
		"C: Pause Psychedelic Mode");
	mlx_string_put(mlx->mlx, mlx->window, 10, 100, 0xFFFFFF,
		"F: Freeze Julia Set");
	mlx_string_put(mlx->mlx, mlx->window, 10, 115, 0xFFFFFF,
		"Esc: Quit");
}
