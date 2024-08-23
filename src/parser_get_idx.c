/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:26:18 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/23 16:48:48 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	get_start(char *line, int i)
{
	while (is_space(line[i]) && line[i])
		i++;
	return (i);
}

int	get_end(char *line, int start)
{
	while (!is_space(line[start]) && line[start])
		start++;
	return (start);
}