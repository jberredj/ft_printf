/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:17:27 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 16:48:44 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_STRUCT_H
# define FLAGS_STRUCT_H
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
typedef struct s_pf
{
	va_list	*ap;
	int		fd;
	int		printed_char;
	int		buf_count;
	char	buffer[BUFFER_SIZE];
	int		flags;
	int		width;
	short	width_state;
	int		precision;
	short	precision_state;
	int		type;
}	t_pf;

#endif