/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:46:53 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/12 13:47:36 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

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
