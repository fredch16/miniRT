/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:28:54 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/12 15:58:09 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	fill_sphere(char *line, t_sp *sphere)
{
	char	**tokens;
	int		success;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	success = tokens[0] && set_coord(tokens[0], &sphere->center) \
				&& tokens[1] && set_dbl(tokens[1], &sphere->diameter) \
				&& tokens[2] && set_rgb(tokens[2], &sphere->col);
	free_tokens(tokens);
	return (success);
}

int	fill_plane(char *line, t_pl *plane)
{
	char	**tokens;
	int		success;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	success = tokens[0] && set_coord(tokens[0], &plane->point) \
				&& tokens[1] && set_vec(tokens[1], &plane->norm_axis_vec) \
				&& tokens[2] && set_rgb(tokens[2], &plane->col);
	free_tokens(tokens);
	return (success);
}

int	fill_cylinder(char *line, t_cy *cylinder)
{
	char	**tokens;
	int		success;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	success = tokens[0] && set_coord(tokens[0], &cylinder->center) \
			&& tokens[1] && set_vec(tokens[1], &cylinder->norm_axis_vec) \
			&& tokens[2] && set_dbl(tokens[2], &cylinder->diameter) \
			&& tokens[3] && set_dbl(tokens[3], &cylinder->height) \
			&& tokens[4] && set_rgb(tokens[4], &cylinder->col);
	if (success && tokens[5] && strlen(tokens[5]) == 1)
		cylinder->cap = tokens[5][0];
	else
		cylinder->cap = -1; /*no info about cap*/
	free_tokens(tokens);
	return (success);
}
