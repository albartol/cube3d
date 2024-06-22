/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:07 by albartol          #+#    #+#             */
/*   Updated: 2024/06/22 18:46:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	print_error(const char *message);
int		in_range(const int value, const int min_value, const int max_value);
int		create_color(const int t, const int r, const int g, const int b);

#endif