/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:51:35 by tordner           #+#    #+#             */
/*   Updated: 2025/08/06 21:13:18 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 1;
	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (s[i - 1] == c)
		count++;
	return (count);
}

static char	*ft_get_word(const char *s, int start, int end)
{
	int		len;
	char	*word;
	int		i;

	i = 0;
	len = end - start;
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	fill_split(char **res, const char *s, char c)
{
	int	i;
	int	start;
	int	word;

	i = 0;
	start = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			res[word++] = ft_get_word(s, start, i);
			start = i + 1;
		}
		i++;
	}
	res[word++] = ft_get_word(s, start, i);
	res[word] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	if (!fill_split(res, s, c))
		return (NULL);
	return (res);
}
