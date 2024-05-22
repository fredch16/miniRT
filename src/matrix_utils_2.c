/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:40:35 by atyurina          #+#    #+#             */
/*   Updated: 2024/05/22 21:40:36 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

//transpose a matrix 
//it turns its rows into columns and its columns into rows
void	matrix_transpose(t_matrix *m)
{
	t_matrix	copy1;
	int			i;
	int			j;

	copy1 = *m;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->matrix[i][j] = copy1.matrix[j][i];
			j++;
		}
		i++;	
	}
}

