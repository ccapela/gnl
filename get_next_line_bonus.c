/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcapela <clcapela@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:11:46 by clcapela          #+#    #+#             */
/*   Updated: 2022/06/30 04:47:53 by clcapela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line(char *aux)
{
	char	*cl;
	int		i;

	i = 0;
	if (!aux[i])
		return (NULL);
	while (aux[i] != '\0' && aux[i] != '\n')
		i++;
	cl = malloc((i + 2) * sizeof(char));
	if (!cl)
		return (NULL);
	i = 0;
	while (aux[i] != '\0' && aux[i] != '\n')
	{
		cl[i] = aux[i];
		i++;
	}
	if (aux[i] == '\n')
		cl[i++] = '\n';
	cl[i] = '\0';
	return (cl);
}

static char	*ft_cut(char *aux)
{
	char	*cl;
	int		index;
	int		cl_i;

	index = 0;
	while (aux[index] != '\n' && aux[index] != '\0')
		index++;
	if (!aux[index])
	{
		free(aux);
		return (NULL);
	}
	cl_i = 0;
	cl = malloc((ft_strlen(aux) - index + 1) * sizeof(char));
	if (!cl)
		return (NULL);
	index++;
	while (aux[index] != '\0')
		cl[cl_i++] = aux[index++];
	cl[cl_i] = '\0';
	free(aux);
	return (cl);
}

static char	*ft_aux(int fd, char *aux)
{
	char	*cl;
	int		count;

	count = 1;
	cl = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!cl)
		return (NULL);
	while (!ft_strchr(aux, '\n') && count != 0)
	{
		count = read(fd, cl, BUFFER_SIZE);
		if (count < 0)
		{
			free(cl);
			return (NULL);
		}
		cl[count] = '\0';
		if (!aux)
		{
			aux = malloc(1 * sizeof(char));
			*aux = '\0';
		}
		aux = ft_strjoin(aux, cl);
	}
	free(cl);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*aux[4096];
	char		*cl1;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	aux[fd] = ft_aux(fd, aux[fd]);
	if (!aux[fd])
		return (NULL);
	cl1 = ft_line(aux[fd]);
	aux[fd] = ft_cut(aux[fd]);
	return (cl1);
}
