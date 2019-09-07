/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecOps2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:50:36 by twitting          #+#    #+#             */
/*   Updated: 2019/09/07 20:16:03 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec v_mult_num(const t_vec v, double t)
{
	t_vec result;

	result.x = v.x * t;
	result.y = v.y * t;
	result.z = v.z * t;
	return result;
}

t_vec v_div_num(const t_vec v, double t)
{
	t_vec result;

	result.x = v.x / t;
	result.y = v.y / t;
	result.z = v.z / t;
	return result;
}

double dot(const t_vec v1, const t_vec v2)
{
	double result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return result;
}

t_vec cross(const t_vec v1, const t_vec v2)
{
	t_vec result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = -1 * (v1.x * v2.z - v1.z * v2.x);
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;
}

t_vec unit_vector(const t_vec v)
{
	t_vec result;

	result = v_div_num(v, v.length);
	return result;
}