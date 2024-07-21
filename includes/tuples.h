/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:46:11 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/18 15:05:59 by atyurina         ###   ########.fr       */
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
t_tuple		tuple_poi(double x, double y, double z);
t_tuple		tuple_vec(double x, double y, double z);
double		tuple_dot(t_tuple a, t_tuple b);
t_tuple	    tuple_cro(t_tuple a, t_tuple b);

#endif
