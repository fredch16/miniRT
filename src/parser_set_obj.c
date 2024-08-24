/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:26:05 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/24 16:54:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
/*****
 * MAYBE THINK OF OTHER WAYS...
 * 
 */
set_sphere(char **scene, t_parser *parser)
{
	int		flag;
	t_sp	sphere;
	flag = 1;
	while (parser->sphere->next != NULL)
	{
		parser->sphere = parser->sphere->next;
		flag = 0;
	}
}

set_plane(char **scene, t_parser *parser)
{
}

set_cylinder(char **scene, t_parser *parser)
{
}