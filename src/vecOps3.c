/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecOps3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:50:26 by twitting          #+#    #+#             */
/*   Updated: 2019/09/07 20:23:30 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec v_new(double x, double y, double z)
{
	t_vec result;

	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

t_ray r_new(const t_vec a, const t_vec b)
{
	t_ray result;

	result.origin = a;
	result.direction = b;
	return result;
}

t_vec point_at_param(double t, const t_vec a, const t_vec b)
{
	t_vec result;
	t_vec tmp;

	tmp = v_mult_num(b, t);
	result = v_plus(a, tmp);
	return result;
}

