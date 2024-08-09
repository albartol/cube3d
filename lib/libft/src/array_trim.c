/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:22:26 by albartol          #+#    #+#             */
/*   Updated: 2024/08/09 12:20:13 by albartol         ###   ########.fr       */
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
