/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:46:11 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/24 13:56:36 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

//tuple utils;
#include "minirt_types.h"

int			equal(double a, double b);
t_tuple		tuple_add(t_tuple a, t_tuple b);
t_tuple		tuple_sub(t_tuple a, t_tuple b);
t_tuple		tuple_neg(t_tuple a);
void		tuple_mul(double mutliplier, t_tuple *a);
double		tuple_abs(t_tuple v);
void		tuple_print(t_tuple v);
t_tuple		tuple_norm(t_tuple v);
double		tuple_dot(t_tuple a, t_tuple b);

#endif
