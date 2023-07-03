/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/20 16:55:42 by mgeisler          #+#    #+#             */
/*   Updated: 2023/02/20 16:55:42 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*emptystack(char *stack, int i)
{
	char	*stock;
	int		size;

	while (stack[i] != '\n' && stack[i])
		i++;
	if (stack[i] == '\n')
		i++;
	size = ft_strlen_gnl(stack + i) + 1;
	if (size == 0)
	{
		free(stack);
		return (NULL);
	}
	stock = ft_calloc(sizeof(char), size + 1);
	if (!stock)
	{
		free(stock);
		free(stack);
		return (NULL);
	}
	while (--size > 0)
		stock[size - 1] = stack[i + size - 1];
	free(stack);
	return (stock);
}

char	*ft_strchr(char *str, char search)
{
	int	i;

	i = 0;
	while (str[i] != search && str[i])
		i++;
	if (str[i] == search)
		return (&*(char *)(str + i));
	else
		return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (s2);
	str = ft_calloc(sizeof(char), (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!str)
	{
		free(s1);
		free(s2);
		free(str);
		str = NULL;
		return (NULL);
	}
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}
