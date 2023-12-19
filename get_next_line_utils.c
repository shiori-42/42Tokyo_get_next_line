/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syonekur <syonekur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:13:19 by syonekur          #+#    #+#             */
/*   Updated: 2023/11/06 20:12:33 by syonekur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_s(char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	pre_len;
	size_t	suf_len;
	char	*ptr;
	char	*org_ptr;

	if (!s1 && !s2)
		return (NULL);
	pre_len = ft_strlen_s(s1);
	suf_len = ft_strlen_s(s2);
	ptr = malloc(pre_len + suf_len + 1);
	if (!ptr)
		return (NULL);
	org_ptr = ptr;
	if (s1)
	{
		while (pre_len--)
			*ptr++ = *s1++;
	}
	if (s2)
	{
		while (suf_len--)
			*ptr++ = *s2++;
	}
	*ptr = '\0';
	return (org_ptr);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ptr;

	if (!s1)
		return (NULL);
	ptr = malloc(ft_strlen_s(s1) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
