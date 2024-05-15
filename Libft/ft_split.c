/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxie <xxie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:04:18 by xxie              #+#    #+#             */
/*   Updated: 2024/05/15 13:38:34 by xxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int end, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[end - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word_i;
	int	word_i_len;

	i = 0;
	word_i = 0;
	word_i_len = 0;
	while (word_i < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_i_len++;
		}
		s2[word_i] = (char *)malloc(sizeof(char) * (word_i_len + 1));
		if (!s2)
			return (free_array(s2, word_i));
		ft_putword(s2[word_i], s, i, word_i_len);
		word_i_len = 0;
		word_i++;
	}
	s2[word_i] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (NULL);
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}
