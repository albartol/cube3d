/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:37:47 by albartol          #+#    #+#             */
/*   Updated: 2024/06/17 14:42:43 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	print_error(const char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (message && *message)
		ft_putstr_fd(message, STDERR_FILENO);
}
