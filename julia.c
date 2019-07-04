/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:09:56 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/07/02 18:52:20 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_julia(int x, int y, t_fractol *fract)
{
	if (fract->fract == 1 && fract->julia_mouse == 1)
	{
		fract->c.r = x * 2;
		fract->c.i = y * 2 - 800;
		fract_calc(fract);
	}
	return (0);
}

void	julia_init(t_fractol *fract)
{
    fract->it_max = 50;
    fract->zoom = 200;
    fract->x1 = -2.0f;
    fract->y1 = -2.0f;
    fract->color = 133742069;
    fract->julia_mouse = 1;
    fract->c.r = 0.285;
	fract->c.i = 0.01;
}

void	julia_calc(t_fractol *fract)
{
	fract->z.r = fract->x / fract->zoom + fract->x1;
	fract->z.i = fract->y / fract->zoom + fract->y1;
	fract->it = 0;
	while (fract->z.r * fract->z.r + fract->z.i
			* fract->z.i < 4 && fract->it < fract->it_max)
	{
		fract->tmp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r -
			fract->z.i * fract->z.i - 0.8 + (fract->c.r / WIN_WIDTH);
		fract->z.i = 2 * fract->z.i * fract->tmp + fract->c.i / WIN_WIDTH;
		fract->it++;
	}
	if (fract->it == fract->it_max)
		image_set_pixel(fract->mlx->image, fract->x, fract->y, 0x000000);
	else
		image_set_pixel(fract->mlx->image, fract->x, fract->y, (fract->color * fract->it));
}

static void	*julia(void *tab)
{
	t_fractol	*fract;
	int			tmp;

	fract = (t_fractol*)tab;
	fract->x = 0;
	tmp = fract->y;
	while (fract->x < WIN_WIDTH)
	{
		fract->y = tmp;
		while (fract->y < fract->y_max)
		{
			julia_calc(fract);
			fract->y++;
		}
		fract->x++;
	}
	return (tab);
}

void	julia_threads(t_fractol *fract)
{
	t_fractol	tab[THREADS];
	pthread_t	t[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)fract, sizeof(t_fractol));
		tab[i].y = (WIN_WIDTH / THREADS) * i;
		tab[i].y_max = (WIN_WIDTH / THREADS) * (i + 1);
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fract->mlx->mlx, fract->mlx->window, 
		fract->mlx->image->image, 0, 0);
}