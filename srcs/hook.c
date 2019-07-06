/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:33:17 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/07/05 22:01:13 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_zoom(int x, int y, t_fractol *fract)
{
	fract->x1 = (x / fract->zoom + fract->x1) - (x / (fract->zoom * 1.5));
	fract->y1 = (y / fract->zoom + fract->y1) - (y / (fract->zoom * 1.5));
	fract->zoom *= 1.5;
	fract->it_max++;
}

void		ft_dezoom(int x, int y, t_fractol *fract)
{
	fract->x1 = (x / fract->zoom + fract->x1) - (x / (fract->zoom / 1.5));
	fract->y1 = (y / fract->zoom + fract->y1) - (y / (fract->zoom / 1.5));
	fract->zoom /= 1.5;
	fract->it_max--;
}

int			mouse_hook(int mousecode, int x, int y, t_fractol *fract)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, fract);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, fract);
	fract_calc(fract);
	return (0);
}

static void	key_hook2(int keycode, t_fractol *fract)
{
	if (keycode == 18)
	{
		fract->color = 42424242;
		fract->psychedelic[0] = 0;
	}
	else if (keycode == 8)
	{
		if (fract->psychedelic[0])
		{
			fract->psychedelic[1] = fract->psychedelic[0];
			fract->psychedelic[0] = 0;
		}
		else
		{
			fract->psychedelic[0] = fract->psychedelic[1];
			fract->psychedelic[1] = 0;
		}
	}
	else if (keycode == 3)
	{
		if (fract->julia_mouse == 1 && fract->fract == 1)
			fract->julia_mouse = 0;
		else if (fract->julia_mouse == 0 && fract->fract == 1)
			fract->julia_mouse = 1;
	}
}

int			key_hook(int keycode, t_fractol *fract)
{
	if (keycode == 53)
		exit(0);
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
	else if (keycode == 21)
		fract->psychedelic[0] = 3;
	else if (keycode == 20)
		fract->psychedelic[0] = 2;
	else if (keycode == 19)
		fract->psychedelic[0] = 1;
	key_hook2(keycode, fract);
	fract_calc(fract);
	return (0);
}
