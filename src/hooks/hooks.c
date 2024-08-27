/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:11:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/27 16:46:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	hooks(void *param)
{
    t_game  *data;

    data = (t_game *)param;
    keys_hook(data);
    draw_all(data);
}
