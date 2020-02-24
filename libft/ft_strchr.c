/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 12:37:38 by tgrangeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/17 18:01:22 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (!(str[i] == c))
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&str[i]);
}

int		ft_strchr_int(char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}
