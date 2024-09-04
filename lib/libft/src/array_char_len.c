/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_char_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:10:51 by albartol          #+#    #+#             */
/*   Updated: 2024/09/04 13:36:31 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	array_char_len(char **array)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (array[i])
	{
		len += ft_strlen(array[i]);
		i++;
	}
	return (len);
}
