/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:51:12 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/24 16:54:27 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dop_func(char *tail, char *temp_buffer)
{
	char	*old_tail;

	old_tail = tail;
	tail = ft_strjoin(old_tail, temp_buffer);
	free(old_tail);
	return (tail);
}

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = ft_strlen(s);
// 	dup = malloc((len + 1) * sizeof(char));
// 	if (dup == 0)
// 		return (0);
// 	while (s[i])
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (s[i] == c)
// 		return ((char *)s + i);
// 	return (0);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	n;

// 	if (!str)
// 		return (0);
// 	n = 0;
// 	while (str[n])
// 		n++;
// 	return (n);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*sub;
// 	size_t	slen;

// 	i = 0;
// 	slen = ft_strlen(s);
// 	if (!s)
// 		return (0);
// 	if (slen < start)
// 		len = 0;
// 	if (len > slen)
// 		len = slen;
// 	else if (len > (slen - start))
// 		len = slen - start;
// 	sub = (char *)malloc((len + 1) * sizeof(char));
// 	if (!sub)
// 		return (0);
// 	while (i < len && i < slen)
// 	{
// 		sub[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	sub[i] = '\0';
// 	return (sub);
// }
