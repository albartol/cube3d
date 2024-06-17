/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:18 by albartol          #+#    #+#             */
/*   Updated: 2024/06/16 23:00:15 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		perror("Wrong number of arguments\n");
	return (EXIT_SUCCESS);
}