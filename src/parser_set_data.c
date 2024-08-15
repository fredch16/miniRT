/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:00:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/15 18:10:49 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
/*
//checks if line is an rgb line
//returns 1 if success, 0 otherwise
int	is_rgb(char *line)
{
	char	**rgb;
	int		num;
	int		i;
	int		ret;

	rgb = ft_split(line, ',');
	i = 0;
	ret = 1;
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			ret = 0;
		i++;
	}
	if (i != 3)
		ret = 0;
	free_double_array(rgb);
	return (ret);
}
*/


/**
 * здесь нужно проверить дабл перед передачи его в ft_atof
 * (пробелы, знаки, любые другие рандомные не подходяшие буквы и тд)
 * и собственно так установить значение
 * затем пройти еще пробелы и проверить rgb и установить
 * return 0 if failed, return 1 if success
*/
int	set_ambient(char *line, t_parser *parser)
{
	int		i;
	int		j;
	char	*dbl;

	i = 2; //start after "A ";
	while (is_space(line[i]) && line[i] != '\0')
		i++;
	j = i;
	while (!is_space(line[j]) && line[j] != '\0')
		j++;
	if (i - j != 0)
	{
		dbl = (char *)malloc((j - i) * sizeof(char));
		strncpy(dbl, i, j);
		//parser->ambient.val = ft_atof
	}
	else
		return (0); ///ERRORRRRR MESSAGEEEE
	return (1);
}

int	set_camera(char *line, t_parser *parser)
{

}

int	set_light(char *line, t_parser *parser)
{

	return(1); //if everything is okay
}

bool	set_data(char **scene, t_parser *parser)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (scene[i] != NULL)
	{
		if (ft_strncmp(scene[i], "A ", 2) == 0)
			count += set_ambient(scene[i], parser);
		else if (ft_strncmp(scene[i], "C ", 2) == 0)
			count += set_camera(scene[i], parser);
		else if (ft_strncmp(scene[i], "L ", 2) == 0)
			count += set_light(scene[i], parser);
		else if(ft_strncmp(scene[i], "sp ", 3) == 0)
			count += set_sphere(scene[i], parser);
		else if (ft_strncmp(scene[i], "pl ", 3) == 0)
			count += set_plane(scene[i], parser);
		else if (ft_strncmp(scene[i], "cy ", 3) == 0)
			count += set_cylinder(scene[i], parser);
	}
	if (count != i)
		return (false);
	return (true);
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