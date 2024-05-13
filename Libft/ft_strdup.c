/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxie <xxie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:23:50 by xxie              #+#    #+#             */
/*   Updated: 2024/05/13 20:29:53 by xxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dst;

	size = ft_strlen(src);
	dst = (char *)malloc(size * sizeof(char) + 1);
	if (dst == NULL)
		return (0);
	ft_memcpy(dst, src, size);
	dst[size] = '\0';
	return (dst);
}
