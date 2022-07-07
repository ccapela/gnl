/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcapela <clcapela@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:14:18 by clcapela          #+#    #+#             */
/*   Updated: 2022/06/30 04:34:50 by clcapela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*ft_aux_join(char *s1, char *s2, char *cl);

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		free(s);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (s + i);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cl;

	if (!s1)
		return (NULL);
	cl = malloc((1 + ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (!cl)
		return (NULL);
	cl = ft_aux_join(s1, s2, cl);
	free(s1);
	return (cl);
}

static char	*ft_aux_join(char *s1, char *s2, char *cl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		cl[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		cl[i] = s2[j];
		i++;
		j++;
	}
	cl[i] = '\0';
	return (cl);
}
