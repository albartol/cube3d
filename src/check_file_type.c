/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:09:31 by albartol          #+#    #+#             */
/*   Updated: 2024/06/23 00:12:41 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	check_file_type(const char *file_path, const char *file_type)
{
	size_t	path_len;
	size_t	type_len;

	path_len = ft_strlen(file_path);
	type_len = ft_strlen(file_type);
	if (path_len <= type_len)
		return (EXIT_FAILURE);
	path_len = path_len - type_len;
	if (ft_strncmp(file_path + path_len, file_type, type_len))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
