/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:33:53 by albartol          #+#    #+#             */
/*   Updated: 2024/09/04 13:36:34 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**array_dup(char **array)
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
		copy[i] = ft_strdup(array[i]);
		if (!copy[i])
		{
			array_free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}
