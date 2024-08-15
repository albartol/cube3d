/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:52:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/10 16:19:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	exit_msg(const char *message, int exit_code)
{
	print_error(message);
	return (exit_code);
}
