/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_char_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:10:51 by albartol          #+#    #+#             */
/*   Updated: 2024/08/09 12:19:52 by albartol         ###   ########.fr       */
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
