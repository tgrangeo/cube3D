/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 00:06:16 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/11/09 00:16:41 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_tab_2D(int	**tab, int line)
{
	int y;

	y = 0;
	while(y < line)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}