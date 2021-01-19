/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:22:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 12:59:31 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PARSER_H
# define CHECKER_PARSER_H
#include "flags_struct.h"
int check_parser(t_pf *flags);
int c_type_illegal(t_pf *flags);
int s_type_illegal(t_pf *flags);
int p_type_illegal(t_pf *flags);
int d_i_type_illegal(t_pf *flags);
int u_type_illegal(t_pf *flags);
int n_type_illegal(t_pf *flags);
int x_type_illegal(t_pf *flags);
int flag_illegal(t_pf *flags);

#endif