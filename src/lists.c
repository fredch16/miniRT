/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:35:21 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/06 19:35:54 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_obj	*obj_create(enum e_obj_type ot)
{
	t_obj	*new;

	new = calloc(1, sizeof(t_obj));
	if (!new)
		return (NULL);
	new->type = ot;
	matrix_set_4(&new->transform);
	return (new);
}

void	obj_add_back(t_obj	**objlist, t_obj *n)
{
	t_obj	*tmp;

	if (!objlist || !n)
		return ;
	if (!*objlist)
		*objlist = n;
	else
	{
		tmp = *objlist;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = n;
	}
}

t_xsn	*x_new(t_obj *o, double x)
{
	t_xsn	*new;

	new = calloc(1, sizeof(t_xsn));
	if (!new)
		return (NULL);
	new->xs_obj = o;
	new->x = x;
	return (new);
}

void	xadd_back(t_xsn	**xslist, t_xsn *n)
{
	t_xsn	*tmp;

	if (!xslist || !n)
		return ;
	if (!*xslist)
		*xslist = n;
	else
	{
		tmp = *xslist;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = n;
	}
}
