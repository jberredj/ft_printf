/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:17:27 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/05 14:35:40 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_STRUCT_H
# define FLAGS_STRUCT_H
# include <stdarg.h>
typedef struct s_pf_flags
{
	int		flags;
	int		width;
	short	width_state;
	int		precision;
	short	precision_state;
	int		length;
	int		type;
	va_list	*list;
	void	*data;
	int		fd;
	int		printed_char;
}	t_pf_flags;

#endif