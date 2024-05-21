/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:26:56 by fcharbon          #+#    #+#             */
/*   Updated: 2023/11/17 14:48:36 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c <= '9' && c >= '0') || ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')))
		return (1);
	else
		return (0);
}
