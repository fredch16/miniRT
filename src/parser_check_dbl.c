/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_dbl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:02:57 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/13 14:53:19 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	set_dbl(const char *dbl, double *dbl_ptr)
{
	if (is_dbl(dbl) == true)
		*dbl_ptr = ft_atof(dbl);
	else
	{
		ft_message_error("Incorrect ambient lighting ratio\n");
		return (false);
	}
	return (true);
}

//checks if a string is a double/int
bool	is_dbl(const char *dbl)
{
	int	i;

	i = 0;
	if (dbl[i] == '-')
		i++;
	while (dbl[i] && dbl[i] >= '0' && dbl[i] <= '9')
		i++;
	if (dbl[i] && dbl[i] == '.' && dbl[i + 1])
		i++;
	else if (dbl[i] == '\0')
		return (true);
	else
		return (false);
	while (dbl[i] && dbl[i] >= '0' && dbl[i] <= '9')
		i++;
	if (dbl[i] == '\0')
		return (true);
	else
		return (false);
}

//converts the beginning of string to double
//
double	ft_atof(const char *str)
{
	double	int_part;
	double	dec_part;
	double	sign;
	int		i;

	int_part = 0.0;
	dec_part = 0.0;
	sign = 1.0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1.0;
	while (ft_isdigit(*str))
		int_part = int_part * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			dec_part += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (int_part + dec_part));
}
