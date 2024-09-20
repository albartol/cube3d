/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:05 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 14:06:09 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	ft_putstr_fd("────────────────────────MAP──────────────────────\n", 1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
				printf(PLAYER_COL);
			else if (map[i][j] == '1')
				printf(WALL_COL);
			printf("%c", map[i][j]);
			printf(RESET);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_putstr_fd("──────────────────────────────────────────────────────\n", 1);
}
