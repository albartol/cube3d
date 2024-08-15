/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:32:05 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/02 14:34:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <cube3d.h>

int free_and_exit(t_game *data, int exit)
{
	free_scene_info(&data->file);
	return (exit);
}
