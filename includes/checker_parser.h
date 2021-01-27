/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:22:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/27 15:05:34 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PARSER_H
# define CHECKER_PARSER_H
# include "flags_struct.h"
# include "parser.h"

void	check_parser(t_pf *flags);
void	c_type_illegal(t_pf *flags);
void	s_type_illegal(t_pf *flags);
void	p_type_illegal(t_pf *flags);
void	d_i_type_illegal(t_pf *flags);
void	u_type_illegal(t_pf *flags);
void	n_type_illegal(t_pf *flags);
void	x_type_illegal(t_pf *flags);
void	flag_illegal(t_pf *flags);
#endif
