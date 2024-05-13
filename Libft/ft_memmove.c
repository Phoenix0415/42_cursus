/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxie <xxie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:46:56 by xxie              #+#    #+#             */
/*   Updated: 2024/05/11 18:44:30 by xxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			j;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	j = 1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		j = -1;
		d += n - 1;
		s += n - 1;
	}
	while (i < n)
	{
		*d = *s;
		d += j;
		s += j;
		i++;
	}
	return (dst);
}
