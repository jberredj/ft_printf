/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:13:02 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/26 16:13:39 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_width(t_pf *flags)
{
	if (flags->width_state == NOT_SET)
		return (0);
	if (flags->flags & MINUS_FLAG)
		return (- flags->width);
	return(flags->width);
}

char	*process_width(char *str, size_t *len, t_pf *flags)
{
	char	*tmp;
	int		width;

	if (str == NULL)
		return (NULL);
	width = check_width(flags);
	if (width <= 0)
		return (str);
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
