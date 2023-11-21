/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:16:48 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/14 15:28:14 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_getline(char *save);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_modifie_save(char *save);
#endif
