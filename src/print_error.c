/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:37:47 by albartol          #+#    #+#             */
/*   Updated: 2024/07/02 12:28:26 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	print_error(const char *message)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (message && *message)
		ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
}
