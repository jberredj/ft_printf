/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:09:09 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 15:05:42 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H
# include <stdlib.h>
# include "flags_struct.h"

typedef unsigned long long	t_uintmax;
void	copy_printed_char(t_pf *flags);
int		convert_int(t_pf *flags);
int		convert_uint(t_pf *flags);
int		convert_char(t_pf *flags);
int		convert_str(t_pf *flags);
int		convert_hex(t_pf *flags, int point);
int		zero_flag(int sign, t_pf *flags);
char	*nbr_precision(char *str, size_t *len, t_pf *flags);
char	*nbr_sign(char *str, int sign, size_t *len, t_pf *flags);
char	*process_width(char *str, size_t *len, char c, t_pf *flags);
void	unbr_size(unsigned long long *unbr, t_pf *flags);
#endif
