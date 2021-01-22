/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:13:02 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/22 14:12:56 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_width(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;
	int		width;

	if (str == NULL)
		return (NULL);
	if (flags->width_state == NOT_SET || flags->width <= 0)
		return (str);
	width = flags->width;
	tmp = ft_calloc(width + *len + 1, sizeof(char));
		if (!tmp)
			return (NULL);
	if (flags->flags & MINUS_FLAG)
	{
		ft_strlcpy(tmp, str, *len + 1);
		ft_memset(&tmp[*len], ' ', width);
	}
	else
	{
		ft_memset(tmp, ' ', width);
		ft_strlcpy(&tmp[width], str, *len + 1);
	}
	free(str);
	*len += flags->width;
	return (tmp);
}