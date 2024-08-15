/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:21:37 by albartol          #+#    #+#             */
/*   Updated: 2024/06/22 18:50:36 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_range(const int value, const int min_value, const int max_value)
{
	if (value < min_value || value > max_value)
		return (0);
	return (1);
}
