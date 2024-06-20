/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:57:05 by albartol          #+#    #+#             */
/*   Updated: 2024/06/20 22:22:27 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	extract_map(t_scene_file *info, size_t list_pos)
{
	t_list	*temp;
	size_t	i;

	temp = info->file_content;
	i = 0;
	while (temp && i++ < list_pos)
		temp = temp->next;
	while (temp && temp->content && *(char *)temp->content == 0)
		temp = temp->next;
	info->map = (char **)ft_calloc(ft_lstsize(temp) + 1, sizeof(char *));
	if (!info->map)
		return (EXIT_FAILURE);
	i = 0;
	while (temp)
	{
		info->map[i] = ft_strdup(temp->content);
		if (!info->map[i])
		{
			array_free(info->map);
			return (EXIT_FAILURE);
		}
		i++;
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
