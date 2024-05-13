/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxie <xxie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:07:36 by xxie              #+#    #+#             */
/*   Updated: 2024/05/11 19:50:41 by xxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_i;
	size_t	d_i;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (!dst && size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	d_i = d_len;
	if (size <= d_len)
		return (size + s_len);
	s_i = 0;
	while (src[s_i] && d_i + 1 < size)
	{
		dst[d_i] = src[s_i];
		s_i++;
		d_i++;
	}
	dst[d_i] = 0;
	return (d_len + s_len);
}
