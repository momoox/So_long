/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:01:31 by mgeisler          #+#    #+#             */
/*   Updated: 2023/02/25 18:01:31 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sortfirst(int fd, char *stack, char *buffer, int onum)
{
	if (!stack)
		stack = ft_calloc(1, 1);
	if (!stack)
		return (0);
	while (onum > 0)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(stack);
			free(buffer);
			return (NULL);
		}
		onum = read(fd, buffer, BUFFER_SIZE);
		if (onum < 0)
			return (NULL);
		stack = ft_strjoin_gnl(stack, buffer);
		if (!stack)
			return (NULL);
		free(buffer);
		buffer = NULL;
		if (ft_strchr(stack, '\n') != 0)
			break ;
	}
	return (stack);
}

char	*findline(char *stack)
{
	int		i;
	char	*line;

	i = 0;
	while (stack[i] != '\n' && stack[i])
		i++;
	if (stack[i] == '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i])
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i] = '\n';
	return (line);
}

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t ecount, size_t esize)
{
	void	*str;

	str = malloc(ecount * esize);
	if (!str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (ecount == 0 || esize == 0)
		return (str);
	if (str == 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	ft_bzero(str, ecount * esize);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*stock;
	static char		*stackito;

	buffer = NULL;
	if (fd < 0 || read(fd, buffer, 0) == -1)
	{
		free(stackito);
		stackito = NULL;
		return (NULL);
	}
	stackito = sortfirst(fd, stackito, buffer, BUFFER_SIZE);
	if (!stackito)
		return (NULL);
	stock = findline(stackito);
	if (!stock || stock[0] == 0)
	{
		free(stock);
		free(stackito);
		stackito = NULL;
		return (NULL);
	}
	stackito = emptystack(stackito, 0);
	return (stock);
}
