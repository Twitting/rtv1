/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:18:13 by twitting          #+#    #+#             */
/*   Updated: 2019/09/07 18:58:46 by twitting         ###   ########.fr       */
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

void    put_pixel(t_mlx *mlx, t_vec *v, int x, int y)
{
    int color = v->r * 256 * 256 + v->g * 256 + v->b;
    mlx->data[y * WWIN + x] = color;
}

void    test(t_mlx *mlx)
{
    int nx = WWIN;
    int ny = HWIN;

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            t_vec v;
            v.x = (float) i / (float) nx;
            v.y = (float) j / (float) ny;
            v.z = 0.2;

            v.r = (int) (255.99 * v.x);
            v.g = (int) (255.99 * v.y);
            v.b = (int) (255.99 * v.z);

            put_pixel(mlx, &v, i, HWIN - 1 - j);
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