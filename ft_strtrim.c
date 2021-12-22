/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:20:13 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/21 19:04:11 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isblank(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
	{
		return (1);
	}
	return (0);
}

static	int	ft_fullblank(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (!ft_isblank(*(s + i++)))
		{
			return (0);
		}
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_fullblank((char *)s1) || *s1 == '\0')
		return (ft_strdup(""));
	length = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + length - 1)) && length != 0)
		length--;
	while (ft_strchr(set, *s1) && length != 0)
	{
		s1++;
		length--;
	}
	return (ft_substr(s1, 0, length));
}
