/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:47:03 by meandrad          #+#    #+#             */
/*   Updated: 2025/01/12 13:13:49 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(const char *string, char ch)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (string[0] != ch && string[0] != '\0')
		counter ++;
	while (string[i] != '\0')
	{
		if (string[i] == ch && string[i + 1] != ch && string[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

static char	*word_allocation(const char *string, char ch)
{
	size_t	length;
	char	*word;

	length = 0;
	while (string[length] != '\0' && string[length] != ch)
		length++;
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, string, length + 1);
	return (word);
}

static int	free_split(char **split, int i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
	return (0);
}

static int	fill(char **split, const char *string, char ch)
{
	int	i;

	i = 0;
	while (*string != '\0')
	{
		if (*string != ch)
		{
			split[i] = word_allocation(string, ch);
			if (!split[i])
				return (free_split(split, i));
			i++;
			while (*string != '\0' && *string != ch)
				string++;
		}
		else
			string++;
	}
	split[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;
	int		result;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	result = fill(split, s, c);
	if (result == 0)
		return (NULL);
	return (split);
}
