/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:32:07 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/07/23 14:00:34 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_calc(t_fractol *fract)
{
	mlx_clear_window(fract->mlx->mlx, fract->mlx->window);
	if (fract->it_max < 0)
		fract->it_max = 0;
	if (fract->fract == 0)
		mandelbrot_threads(fract);
	else if (fract->fract == 1)
		julia_threads(fract);
	else if (fract->fract == 2)
		burningship_threads(fract);
	else if (fract->fract == 3)
		tricorn_threads(fract);
}

void	fract_init(t_fractol *fract)
{
	fract->psychedelic[0] = 0;
	fract->psychedelic[1] = 0;
	if (fract->fract == 0)
		mandelbrot_init(fract);
	else if (fract->fract == 1)
		julia_init(fract);
	else if (fract->fract == 2)
		burningship_init(fract);
	else if (fract->fract == 3)
		tricorn_init(fract);
	fract_calc(fract);
}

void	mlx_win_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	mlx->image = new_image(mlx);
}

int		fract_compare(char **argv, t_fractol *fract)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fract->fract = 0;
	else if (!ft_strcmp(argv[1], "julia"))
		fract->fract = 1;
	else if (!ft_strcmp(argv[1], "burningship"))
		fract->fract = 2;
	else if (!ft_strcmp(argv[1], "tricorn"))
		fract->fract = 3;
	else
	{
		ft_putstr("Usage: fractol \"mandelbrot\", ");
		ft_putendl("\"julia\", \"burningship\", \"tricorn\"");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	*fract;
	t_mlx		*mlx;

	if (!(fract = (t_fractol*)ft_memalloc(sizeof(t_fractol)))
	|| !(mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
		return (-1);
	if (argc == 2)
	{
		if (!fract_compare(argv, fract))
			return (0);
		mlx_win_init(mlx);
		fract->mlx = mlx;
		fract_init(fract);
		mlx_hook(mlx->window, 6, 0, mouse_julia, fract);
		mlx_mouse_hook(mlx->window, mouse_hook, fract);
		mlx_key_hook(mlx->window, key_hook, fract);
		mlx_hook(mlx->window, 17, 0, ft_close, fract);
		mlx_loop(mlx->mlx);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\", \"tricorn\"");
	return (0);
}
