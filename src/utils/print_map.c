/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:05 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/27 15:08:56 by albartol         ###   ########.fr       */
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
				ft_putstr_fd(PLAYER_COL, STDOUT_FILENO);
			else if (map[i][j] == '1')
				ft_putstr_fd(WALL_COL, STDOUT_FILENO);
			ft_putchar_fd(map[i][j], STDOUT_FILENO);
			ft_putstr_fd(RESET, STDOUT_FILENO);
			j++;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("─────────────────────────────────────────────────\n", 1);
}
