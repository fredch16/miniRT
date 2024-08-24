/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:44:14 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/24 16:51:37 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "minirt_types.h"

//parser_read
char	**file_read(char *file);
void	ft_message_error(char *str);

//parser_check_element
bool	file_check_rt(char *file);
int		times_met(char **text, char a);
bool	file_check_capital(char **text);
bool	file_check_line(char **line);
int		is_space(int c);

//parser_check
bool	file_check_error(char **scene);
bool	file_wrong_element(char **text);
bool	find_needle(char *line);
void	free_text(char **text);

//parser_set_data
bool	set_data(char **scene, t_parser *parser);
void	set_next_null(t_parser *parser);
int		set_ambient(char *line, t_parser *parser);
int		set_camera(char *line, t_parser *parser);
int		set_light(char *line, t_parser *parser);

//parset_set_obj
int		set_sphere(char **scene, t_parser *parser);
int		set_plane(char **scene, t_parser *parser);
int		set_cylinder(char **scene, t_parser *parser);
//parser_check_dbl

bool	is_dbl(const char *dbl);
double	ft_atof(const char *str);
bool	set_dbl(const char *line, int i, int j, double *dbl_ptr);

//parser_check_rgb
bool	set_rgb(char *line, int e, int s, t_colour *col);
void	free_double_array(char **array);
bool	is_rgb(char *line);
bool	check_rbg_format(char *line);

//parser_check_coord
bool	set_coord(const char *line, int i, int j, t_tuple *point);
bool	is_coord(char *line);
bool	in_range(double d);

//parser_get_idx
int	get_start(char *line, int i);
int	get_end(char *line, int start);

#endif