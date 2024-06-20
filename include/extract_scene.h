/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_scene.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:09:48 by albartol          #+#    #+#             */
/*   Updated: 2024/06/20 21:34:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACT_SCENE_H
# define EXTRACT_SCENE_H

#include <cube3d.h>

// element type identifiers
# define NO "NO"
# define SO "SO"
# define EA "EA"
# define WE "WE"
# define F "F"
# define C "C"

size_t	extract_elements(t_scene_file *info);
int		extract_map(t_scene_file *info, size_t list_pos);

#endif