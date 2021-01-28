/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:57:40 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/28 11:46:22 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_intlen(int n);
int		ft_isdigit(int c);
char	*ft_lltoa(long long n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_ulltoa_base(unsigned long long n, char *base);
char	*ft_ulltoa(unsigned long long n);
size_t	ft_ulllen(unsigned long long n);
int		ft_isspace(int c);
int		check_base(char *str);
size_t	ft_ulllen_base(unsigned long long n, int base);
size_t	ft_lllen(long long n);
#endif
