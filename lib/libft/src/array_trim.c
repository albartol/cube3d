/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:22:26 by albartol          #+#    #+#             */
/*   Updated: 2024/09/04 13:36:44 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**array_trim(char **array, const char *set)
{
	char	**copy;
	int		len;
	int		i;

	len = array_len(array);
	copy = ft_calloc(len + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = ft_strtrim(array[i], set);
		if (!copy[i])
		{
			array_free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}
