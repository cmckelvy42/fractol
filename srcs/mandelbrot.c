/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:31:50 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/07/05 22:06:23 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot_init(t_fractol *fract)
{
	fract->it_max = 50;
	fract->zoom = 200;
	fract->x1 = -2.25f;
	fract->y1 = -1.5f;
	fract->color = 42424242;
}

static void	mandelbrot_calc(t_fractol *fract)
{
	fract->c.r = fract->x / fract->zoom + fract->x1;
	fract->c.i = fract->y / fract->zoom + fract->y1;
	fract->z.r = 0;
	fract->z.i = 0;
	fract->it = 0;
	while (fract->z.r * fract->z.r + fract->z.i * fract->z.i < 4
			&& fract->it < fract->it_max)
	{
		fract->tmp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i * fract->z.i +
			fract->c.r;
		fract->z.i = 2 * fract->z.i * fract->tmp + fract->c.i;
		fract->it++;
	}
	if (fract->it == fract->it_max)
		image_set_pixel(fract->mlx->image, fract->x, fract->y, 0x000000);
	else
		image_set_pixel(fract->mlx->image, fract->x, fract->y,
			(fract->color * fract->it));
}

static void	*mandelbrot(void *tab)
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
			mandelbrot_calc(fract);
			fract->y++;
		}
		fract->x++;
	}
	return (tab);
}

void		mandelbrot_threads(t_fractol *fract)
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
		pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fract->mlx->mlx, fract->mlx->window,
		fract->mlx->image->image, 0, 0);
	print_help(fract->mlx);
}
