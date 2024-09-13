/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_dbl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:02:57 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/13 17:05:52 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	set_dbl(const char *line, int i, int j, double *dbl_ptr)
{
	char	*dbl;

	dbl = (char *)malloc((j - i + 1) * sizeof(char));
	ft_strlcpy(dbl, line + i, j - i + 1);
	if (is_dbl(dbl) == true)
		*dbl_ptr = ft_atof(dbl);
	else
	{
		free(dbl);
		ft_message_error("Incorrect ambient lighting ratio\n");
		return (false);
	}
	free(dbl);
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
	if (dbl[i] == '.' && dbl[i])
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
double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	res2 /= pow(10, len);
	if (res >= 0)
		return (res + res2);
	else
		return (res + -res2);
}
