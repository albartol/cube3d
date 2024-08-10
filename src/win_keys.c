/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:52 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/10 17:23:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>


void	key_events(void *param)
{
	t_display	*game;

	game = (t_display *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		printf("Adiooooossss");
	}
}
