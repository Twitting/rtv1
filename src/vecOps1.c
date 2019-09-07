/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecOps1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:50:26 by twitting          #+#    #+#             */
/*   Updated: 2019/09/07 17:54:07 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec v_plus(const t_vec *v1, const t_vec *v2)
{
	t_vec result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return result;
}

t_vec v_minus(const t_vec *v1, const t_vec *v2)
{
	t_vec result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return result;
}

t_vec v_mult(const t_vec *v1, const t_vec *v2)
{
	t_vec result;

	result.x = v1->x * v2->x;
	result.y = v1->y * v2->y;
	result.z = v1->z * v2->z;
	return result;
}

t_vec v_div(const t_vec *v1, const t_vec *v2)
{
	t_vec result;

	result.x = v1->x / v2->x;
	result.y = v1->y / v2->y;
	result.z = v1->z / v2->z;
	return result;
}