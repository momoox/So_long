/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:54:31 by mgeisler          #+#    #+#             */
/*   Updated: 2023/07/12 19:28:12 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// size_t	count(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	words;

// 	i = 0;
// 	words = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
// 			words++;
// 		i++;
// 	}
// 	return (words);
// }

// size_t	lenword(const char *s, size_t i, char c)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[i] == c)
// 		i++;
// 	while (s[i] != c && s[i])
// 	{
// 		len++;
// 		i++;
// 	}
// 	return (len);
// }

// char	*cpyword(const char *s, size_t *i, char c, size_t len)
// {
// 	char	*str;
// 	size_t	u;

// 	u = 0;
// 	while (s[*i] == c)
// 		(*i)++;
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	while (len)
// 	{
// 		str[u++] = s[(*i)++];
// 		len--;
// 	}
// 	str[u] = '\0';
// 	return (str);
// }

// char	**freeall(char **tab)
// {
// 	size_t	j;

// 	j = 0;
// 	while (tab[j])
// 	{
// 		free(tab[j]);
// 		j++;
// 	}
// 	free(tab);
// 	return (NULL);
// }

// char	**ft_split(const char *s, char c)
// {
// 	size_t		i;
// 	size_t		j;
// 	char		**tab;

// 	i = 0;
// 	j = 0;
// 	if (!s)
// 		return (0);
// 	tab = malloc(sizeof(char *) * (count(s, c)) + 1);
// 	if (!tab)
// 		return (0);
// 	while (j < count(s, c))
// 	{
// 		tab[j++] = cpyword(s, &i, c, lenword(s, i, c));
// 		if (!tab[j - 1])
// 			return (freeall(tab));
// 	}
// 	tab[j] = NULL;
// 	return (tab);
// }

static size_t	nextlen(const char *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static size_t	wordcount(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 1;
	count = 0;
	while (s[i - 1])
	{
		if (i != 0 && s[i - 1] != c && (s[i] == c || !s[i]))
			count++;
		i++;
	}
	return (count);
}

static char	*nextword(const char *s, size_t *i, char c, size_t len)
{
	char	*cpy;
	size_t	y;

	y = 0;
	while (s[*i] == c)
		(*i)++;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (len)
	{
		cpy[y++] = s[(*i)++];
		len--;
	}
	cpy[y] = '\0';
	return (cpy);
}

static char	**freeall_split(char **tab, size_t indice)
{
	size_t	y;

	y = 0;
	while (y <= indice)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	y;
	char	**tab;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	while (y < wordcount(s, c))
	{
		tab[y] = nextword(s, &i, c, nextlen(s, i, c));
		if (!tab[y])
			return (freeall_split(tab, y));
		y++;
	}
	tab[wordcount(s, c)] = NULL;
	return (tab);
}
