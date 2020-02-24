/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 16:47:57 by tgrangeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/17 17:36:31 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!(s))
		return (NULL);
	if (!(dest = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if ((int)start > ft_strlen(s))
	{
		dest[i] = '\0';
		return (dest);
	}
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_substr_free(char *s, int start, int len)
{
	int		i;
	char	*dest;

	if (!(s))
		return (NULL);
	if (!(dest = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
	{
		dest[i] = '\0';
		return (dest);
	}
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	free(s);
	return (dest);
}
