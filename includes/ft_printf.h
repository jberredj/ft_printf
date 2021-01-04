/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:32:20 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/04 19:25:21 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include "ft_pf_parser.h"
# include "parser_flag.h"
# include "parser_length.h"
# include "parser_type.h"
typedef struct s_pf_flags
{
	int		flags;
	int		width;
	short	width_state;
	int		precision;
	short	precision_state;
	int		length;
	int		type;
	void	*data;
	int		fd;
}	t_pf_flags;
void	print_int(t_pf_flags flags);

#endif