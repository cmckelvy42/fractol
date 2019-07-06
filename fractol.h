/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:32:38 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/07/05 22:10:52 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH	600
# define WIN_HEIGHT	600
# define THREADS	10

# include "./libft/includes/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
}				t_mlx;

typedef struct	s_mouse
{
	int			isclick;
	int			lastx;
	int			lasty;
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_fractol
{
	t_mlx		*mlx;
	int			fract;
	int			color;
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	double		zoom;
	double		x1;
	double		y1;
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			psychedelic[2];
}				t_fractol;

t_image			*new_image(t_mlx *mlx);
void			image_set_pixel(t_image *image, int x, int y, int color);
void			fract_init(t_fractol *fract);
void			mandelbrot_init(t_fractol *fract);
void			mandelbrot_threads(t_fractol *fract);
void			tricorn_init(t_fractol *fract);
void			tricorn_threads(t_fractol *fract);
void			burningship_init(t_fractol *fract);
void			burningship_threads(t_fractol *fract);
int				mouse_hook(int mousecode, int x, int y, t_fractol *fract);
void			fract_calc(t_fractol *fract);
void			clear_image(t_image *image);
int				mouse_julia(int x, int y, t_fractol *fract);
void			julia_init(t_fractol *fract);
void			julia_threads(t_fractol *fract);
int				key_hook(int keycode, t_fractol *fract);
int				ft_close(void);
void			print_help(t_mlx *mlx);
#endif
