/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:32:20 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 16:22:45 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "flags_struct.h"
# include "buffer.h"
# include "parser.h"
# include "checker_parser.h"
# include "converter.h"
# include "minilibft.h"
# ifndef BONUS
#  define BONUS 0
# endif

int		ft_printf(const char *str, ...);
void	clear_flags(t_pf *flags);
void	init_flags(t_pf *flags);
#endif
