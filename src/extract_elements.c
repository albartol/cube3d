/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:56:48 by albartol          #+#    #+#             */
/*   Updated: 2024/06/20 21:48:07 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <extract_scene.h>

static size_t	identifier_len(char *content)
{
	size_t	len;
	char	spaces;

	len = 0;
	spaces = 0;
	if (!content)
		return (0);
	while (content[len])
	{
		if (!spaces && content[len] != ' ')
			spaces = !spaces;
		else if (spaces && content[len] == ' ')
			break ;
		len++;
	}
	return (len);
}

static char	*get_value(char *content)
{
	size_t	identifier_pos;
	char	*value;

	identifier_pos = identifier_len(content);
	if (!identifier_pos || identifier_pos > UINT_MAX)
		return (NULL);
	while (content[identifier_pos] == ' ')
		identifier_pos++;
	if (identifier_pos > UINT_MAX)
		return (NULL);
	value = ft_substr(content, identifier_pos, ft_strlen(content));
	if (!value)
		perror(NULL);
	return (value);
}

static int	cmp_type(char *storage, char *type, char *content, size_t len)
{
	if (storage)
		return (0);
	if (len != ft_strlen(type))
		return (0);
	if (ft_strncmp(type, content, len))
		return (0);
	return (1);
}

static int	check_identifiers(t_scene_file *info, char *content, size_t len)
{
	if (cmp_type(info->north_texture, NO, content, len))
		info->north_texture = get_value(content);
	else if (cmp_type(info->south_texture, SO, content, len))
		info->south_texture = get_value(content);
	else if (cmp_type(info->east_texture, EA, content, len))
		info->east_texture = get_value(content);
	else if (cmp_type(info->west_texture, WE, content, len))
		info->west_texture = get_value(content);
	else if (cmp_type(info->floor_color, F, content, len))
		info->floor_color = get_value(content);
	else if (cmp_type(info->celling_color, C, content, len))
		info->celling_color = get_value(content);
	else
		return (1);
	return (0);
}

size_t	extract_elements(t_scene_file *info)
{
	t_list	*temp;
	size_t	len;
	size_t	list_pos;

	list_pos = 0;
	temp = info->file_content;
	while (temp)
	{
		len = identifier_len(temp->content);
		if (len >= 1 && check_identifiers(info, temp->content, len))
		{
			ft_putstr_fd(temp->content, STDERR_FILENO);
			ft_putstr_fd(" : is an invalid element\n", STDERR_FILENO);
			return (0);
		}
		if (errno == ENOMEM)
			return (0);
		list_pos++;
		temp = temp->next;
		if (info->north_texture && info->south_texture
			&& info->east_texture && info->west_texture
			&& info->floor_color && info->celling_color)
			break ;
	}
	return (list_pos);
}
