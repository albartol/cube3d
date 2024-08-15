/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/08/15 20:02:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static int	check_color_str(const char *color)
{
	size_t	i;
	int		num_coma;
	int		last_coma;

	i = 0;
	num_coma = 0;
	last_coma = 1;
	while (color[i])
	{
		if (color[i] != ' ' && !ft_isdigit(color[i])
			&& (color[i] != ',' || last_coma || num_coma >= 2))
			return (EXIT_FAILURE);
		else if (color[i] == ',')
		{
			last_coma = 1;
			num_coma++;
		}
		else if (color[i] != ' ')
			last_coma = 0;
		i++;
	}
	if (num_coma != 2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	color_str_to_int(const char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) || i > 3)
			return (-1);
		i++;
	}
	return (ft_atoi(color));
}

static int	validate_color_str(const char *color, uint32_t *final_color)
{
	char	**color_array;
	char	**temp;
	int		rgb[3];

	temp = ft_split(color, ',');
	if (!temp)
		return (EXIT_FAILURE);
	if (array_len((const char **)temp) != 3)
	{
		array_free(temp);
		return (EXIT_FAILURE);
	}
	color_array = array_trim((const char **)temp, " ");
	array_free(temp);
	if (!color_array)
		return (EXIT_FAILURE);
	rgb[0] = color_str_to_int(color_array[0]);
	rgb[1] = color_str_to_int(color_array[1]);
	rgb[2] = color_str_to_int(color_array[2]);
	array_free(color_array);
	if (!in_range(rgb[0], 0, 255) || !in_range(rgb[1], 0, 255)
		|| !in_range(rgb[2], 0, 255))
		return (EXIT_FAILURE);
	*final_color = create_color(255, rgb[0], rgb[1], rgb[2]);
	return (EXIT_SUCCESS);
}

int	check_colors(char *floor_color, char *celling_color, t_scene *scene)
{
	if (check_color_str(floor_color) || check_color_str(celling_color))
		return (EXIT_FAILURE);
	if (validate_color_str(floor_color, &scene->floor_color)
		|| validate_color_str(celling_color, &scene->celling_color))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
