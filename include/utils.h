/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:07 by albartol          #+#    #+#             */
/*   Updated: 2024/07/10 16:19:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	print_error(const char *message);
int		check_file_type(const char *file_path, const char *file_type);
int		in_range(const int value, const int min_value, const int max_value);
int		create_color(const int t, const int r, const int g, const int b);
int		exit_msg(const char *message, int exit_code);

#endif