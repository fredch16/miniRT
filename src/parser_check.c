/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:34:02 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/25 13:46:07 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	file_check_error(char **text)
{
	if (file_check_capital(text) == false || file_wrong_element(text) == false)
		return (false);
	return (true);
}

/**
 *  check separately data of each line: A, C, L, pl, sp, cy. If wrong data -> Error
*/

// Program must take as a first argument a scene description file with the .rt
// extension.
// ◦ Each type of element can be separated by one or more line break(s).
// ◦ Each type of information from an element can be separated by one or more
// space(s).
// ◦ Each type of element can be set in any order in the file.
// ◦ Elements which are defined by a capital letter can only be declared once in
// the scene.
