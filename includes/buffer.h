/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:08:35 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 15:03:32 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include "flags_struct.h"
# include <unistd.h>

void	add_to_buffer(char *str, int len, t_pf *flags);
void	print_buffer(t_pf *flags);
#endif
