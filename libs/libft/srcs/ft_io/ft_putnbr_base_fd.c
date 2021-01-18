/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:05:48 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/18 11:17:53 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static int check_base(char *str)
{
	int	i;
	int j;

	if (*str == '\0' || str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (-1);
		j = 0;
		while (str[j])
		{
			if (str[j] == str[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int print_base(int n, char *str, size_t len, int fd)
{
	unsigned int	us_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		us_n = (unsigned int)n;
		us_n = -us_n;
	}
	else
		us_n = (unsigned int)(n);
	if (us_n >= len)
	{
		print_base(us_n / len, str, len, fd);
	}
	ft_putchar_fd(str[us_n % len], fd);
	return (0);
}

void	ft_putnbr_base_fd(int n, char *str, int fd)
{
	size_t			len;

	len = check_base(str);
	if (len < 2)
		return ;
	print_base(n, str, len , fd);
}
