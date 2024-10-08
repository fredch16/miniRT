/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:35:21 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/24 16:30:49 by fcharbon         ###   ########.fr       */
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
	if (ot == OT_CYLINDER)
	{
		new->max = DBL_MAX;
		new->min = DBL_MIN;
		new->capped = true;
	}
	matrix_set_4(&new->transform);
	new->material = material_set_default();
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

void	free_xs(t_xsn **xslist)
{
	t_xsn	*to_free;
	t_xsn	*tmp;

	if (!xslist || !*xslist)
		return ;
	tmp = *xslist;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp -> next;
		free(to_free);
	}
	*xslist = NULL;
}

void	free_obj(t_obj **objlist)
{
	t_obj	*to_free;
	t_obj	*tmp;

	if (!objlist || !*objlist)
		return ;
	tmp = *objlist;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp -> next;
		free(to_free);
	}
	*objlist = NULL;
}
