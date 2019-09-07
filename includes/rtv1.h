/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:09:32 by twitting          #+#    #+#             */
/*   Updated: 2019/09/07 20:21:40 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

// # define double float

typedef struct      s_vec
{
    double      x;
    double      y;
    double      z;
    double      r;
    double      g;
    double      b;
    double      length;
}                   t_vec;

typedef struct		s_ray
{
	t_vec		origin;
	t_vec		direction;
}					t_ray;

typedef struct		s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}					t_mlx;

typedef struct		s_coord
{
	t_vec		llc;//lower left corner
	t_vec		h;//horizontal
	t_vec		v;//vertical
	t_vec		o;//origin
}					t_coord;

t_vec v_new(double x, double y, double z);
t_ray r_new(const t_vec v1, const t_vec v2);
t_vec v_plus(const t_vec v1, const t_vec v2);
t_vec v_minus(const t_vec v1, const t_vec v2);
t_vec v_mult(const t_vec v1, const t_vec v2);
t_vec v_div(const t_vec v1, const t_vec v2);
t_vec v_mult_num(const t_vec v, double t);
t_vec v_div_num(const t_vec v, double t);
double dot(const t_vec v1, const t_vec v2);
t_vec cross(const t_vec v1, const t_vec v2);
t_vec point_at_param(double t, const t_vec a, const t_vec b);
t_vec unit_vector(const t_vec v);
t_vec color(const t_ray r);
int		keyboard(int key, void *mlx);
t_coord init_coord();

#endif