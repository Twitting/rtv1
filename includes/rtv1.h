/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:09:32 by twitting          #+#    #+#             */
/*   Updated: 2019/09/07 17:03:20 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"

// # define WINSIZE 900

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

t_vec v_plus(const *t_vec v1, const *t_vec v2);
t_vec v_minus(const *t_vec v1, const *t_vec v2);
t_vec v_mult(const *t_vec v1, const *t_vec v2);
t_vec v_div(const *t_vec v1, const *t_vec v2);
*t_vec v_multNum(const *t_vec v, float t);
*t_vec v_divNum(const *t_vec v, float t);
float dot(const *t_vec v1, const *t_vec v2);
t_vec cross(const *t_vec v1, const *t_vec v2);

#endif
