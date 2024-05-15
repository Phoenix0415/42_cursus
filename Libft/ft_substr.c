/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxie <xxie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:16:07 by xxie              #+#    #+#             */
/*   Updated: 2024/05/14 23:14:47 by xxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	slen;
	size_t	sublen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	sublen = slen - start;
	if (sublen > len)
		sublen = len;
	substring = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!substring)
		return (0);
	ft_strlcpy(substring, s + start, sublen + 1);
	return (substring);
}
