/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:18:13 by twitting          #+#    #+#             */
/*   Updated: 2019/09/07 20:31:47 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

# define WWIN 1200
# define HWIN 600

void    init(t_mlx *mlx)
{
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WWIN, HWIN, "dno");
    mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WWIN, HWIN);
    mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_l, &mlx->endian);
}

t_coord init_coord()
{
    t_coord result;

    result.llc = v_new(-2.0, -1.0, -1.0);
    result.h = v_new(4.0, 0.0, 0.0);
    result.v = v_new(0.0, 2.0, 0.0);
    result.o = v_new(0.0, 2.0, 0.0);
    return result;
}

void    put_pixel(t_mlx *mlx, t_vec *v, int x, int y)
{
    int color = v->r * 256 * 256 + v->g * 256 + v->b;
    mlx->data[y * WWIN + x] = color;
}

t_vec color(const t_ray r)
{
	t_vec unit_direction;
	float t;

	unit_direction = unit_vector(r.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return v_plus(
		v_mult_num(v_new(1.0, 1.0, 1.0), 1.0 - t),
		v_mult_num(v_new(0.5, 0.7, 1.0), t)
		);
}

void    test(t_mlx *mlx)
{
    int nx = WWIN;
    int ny = HWIN;
    t_ray r;
    t_vec vec;
    t_coord c; // coordination system

    c = init_coord();
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            double u = (double) i / (double) nx;
            double v = (double) j / (double) ny;
            r = r_new(c.o, 
            v_plus(c.llc, 
            v_plus(
                v_mult_num(c.h, u), 
                v_mult_num(c.v, v)
                )));
            vec = color(r);
            vec.r = (int) (255.99 * vec.x);
            vec.g = (int) (255.99 * vec.y);
            vec.b = (int) (255.99 * vec.z);

            put_pixel(mlx, &vec, i, HWIN - 1 - j);
        }
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

int     main(int argc, char **argv)
{
    t_mlx mlx;

    init(&mlx);
    test(&mlx);
    mlx_key_hook(mlx.win_ptr, keyboard, (void *)&mlx);
    mlx_loop(mlx.mlx_ptr);
    //start render;
    return (0);
}