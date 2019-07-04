/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 22:26:51 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/07/03 17:11:20 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(int x, int y, t_fractol *fract)
{
	fract->x1 = (x / fract->zoom + fract->x1) - (x / (fract->zoom * 1.5));
	fract->y1 = (y / fract->zoom + fract->y1) - (y / (fract->zoom * 1.5));
	fract->zoom *= 1.5;
	fract->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *fract)
{
	fract->x1 = (x / fract->zoom + fract->x1) - (x / (fract->zoom / 1.5));
	fract->y1 = (y / fract->zoom + fract->y1) - (y / (fract->zoom / 1.5));
	fract->zoom /= 1.5;
	fract->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *fract)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, fract);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, fract);
    fract_calc(fract);
	return (0);
}

int		key_hook(int keycode, t_fractol *fract)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		fract->it_max += 50;
	else if (keycode == 78)
		fract->it_max -= 50;
	else if (keycode == 123)
		fract->x1 -= 30 / fract->zoom;
	else if (keycode == 124)
		fract->x1 += 30 / fract->zoom;
	else if (keycode == 125)
		fract->y1 += 30 / fract->zoom;
	else if (keycode == 126)
		fract->y1 -= 30 / fract->zoom;
	else if (keycode == 49)
		fract_init(fract);
	else if (keycode == 18)
		fract->color = 265;
	fract_calc(fract);
	return (0);
}