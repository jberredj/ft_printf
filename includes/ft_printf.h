/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:32:20 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/22 15:19:57 by jberredj         ###   ########.fr       */
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
# include "../libft/includes/ft_string.h"
# include "../libft/includes/ft_to.h"
# include "../libft/includes/ft_ctype.h"
# ifndef BONUS
#  define BONUS 0
# endif
int		ft_printf(const char *str, ...);
int		clear_flags(t_pf *flags);
int		init_flags(t_pf *flags);

#endif