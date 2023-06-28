/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:21:04 by yalthaus          #+#    #+#             */
/*   Updated: 2021/10/16 05:55:15 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_cstrlen(dst);
	if (dstsize <= i)
		return (dstsize + ft_cstrlen((char *)src));
	j = 0;
	while (*(src + j) && i + 1 < dstsize)
	{
		*(dst + i) = *(src + j);
		i++;
		j++;
	}
	*(dst + i) = '\0';
	return (ft_cstrlen(dst) + ft_cstrlen((char *)src + j));
}
