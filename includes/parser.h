/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:44:14 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/25 13:44:36 by atyurina         ###   ########.fr       */
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

#endif