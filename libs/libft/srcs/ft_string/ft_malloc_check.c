/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:31:43 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/19 15:34:40 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int ft_malloc_check(void **p, size_t nmemb, size_t size)
{
	p = malloc(nmemb * size);
	if (p != NULL)
		ft_bzero(p, nmemb * size);
	if (p ==  NULL)
		return (-1);
	return (0);
}