/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:37:57 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/11 18:37:59 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

#include "minirt_types.h"

//sphere_normal:
t_tuple	sphere_normal_at(t_obj *s, t_tuple *w_point);
t_tuple	reflect(t_tuple *in, t_tuple *normal);

#endif