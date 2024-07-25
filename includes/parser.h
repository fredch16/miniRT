/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:44:14 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/24 16:50:37 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "minirt_types.h"

//parser_read
char	**file_read(char *file);
void	ft_message_error(char *str);

//parser_check
bool	file_check_rt(char *file);
bool	file_check_error(char **scene);

#endif