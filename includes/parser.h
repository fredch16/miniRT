/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:44:14 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/27 14:42:09 by atyurina         ###   ########.fr       */
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
int		is_space(int c);

//parser_check
bool	file_check_error(char **scene);
bool	file_wrong_element(char **text);
bool	find_needle(char *line);
void	free_text(char **text);

//parser_set_data
bool	set_data(char **scene, t_parser *parser);
void	set_zeros_obj(t_parser *parser);
int		set_ambient(char *line, t_parser *parser);
int		set_camera(char *line, t_parser *parser);
int		set_light(char *line, t_parser *parser);

//parser_set_obj
int		set_sphere(char *scene, t_parser *parser);
int		set_plane(char *scene, t_parser *parser);
int		set_cylinder(char *scene, t_parser *parser);

//parser_fill_obj
int	fill_sphere(char *line, t_sp *sphere);
int	fill_plane(char *line, t_pl	*plane);
int	fill_cylinder(char *line, t_cy	*cylinder);

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

//parser_set_vec
bool	set_vec(const char *line, int i, int j, t_tuple *tuple);
bool	in_range(double d);
bool	is_vec(char *line);

#endif