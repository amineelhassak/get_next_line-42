/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:54:20 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/14 15:24:08 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!*save)
		return ((char *)0);
	while (save[i] != '\n' && *(save + i))
		i++;
	if (save[i] == '\n')
		str = malloc(((i + 2) * sizeof(char)));
	else
		str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (*(save + i) != '\n' && *(save + i))
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_modifie_save(char *save)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || (save[i] == '\n' && save[i + 1] == '\0'))
	{
		free(save);
		return (NULL);
	}
	str = malloc((ft_strlen(save)- i + 2) * sizeof(char));
	if (!str)
		return (0);
	i++;
	k = 0;
	while (save[i])
		str[k++] = save[i++];
	str[k] = '\0';
	free(save);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		n;
	int		m;
	int		i;
	int		j;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	i = -1;
	tab = (char *)malloc(m + n + 1);
	if (!tab)
		return (0);
	while (*(s1 + (++i)))
		tab[i] = s1[i];
	j = -1;
	while ((++j) < m)
		tab[i + j] = s2[j];
	tab[i + j] = '\0';
	return (free((void *)s1), tab);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char )c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)(s + i));
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count))
		count++;
	return (count);
}
