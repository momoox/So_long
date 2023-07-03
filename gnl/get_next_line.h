/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:49:15 by mgeisler          #+#    #+#             */
/*   Updated: 2023/03/15 17:49:15 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *s);
char	*ft_strchr(char *str, char search);
void	*ft_calloc(size_t ecount, size_t esize);
void	ft_bzero(void *s, size_t len);
char	*findline(char *stack);
char	*emptystack(char *stack, int i);
char	*sortfirst(int fd, char *stack, char *buffer, int onum);

#endif
