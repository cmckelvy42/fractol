/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:56:51 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/04 17:02:52 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strccpy(char *dst, char *src, char c)
{
	int i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
