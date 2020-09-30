/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thomasgrangeon <thomasgrangeon@student.    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/04/15 07:58:27 by thomasgrang  #+#   ##    ##    #+#       */
/*   Updated: 2020/04/27 10:06:25 by thomasgrang ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/cube3d.h"


void afficherTableau(int **grille, int x, int y)
{
    int i;
    int j;
    for(i=0; i<x; i++)
    {
		printf("%d:", i);
        for(j=0; j<y; j++)
        {
            printf("%d", grille[i][j]);
 
        }
        printf("\n");
    }
}

void	ft_ligne(int *map, char *str, int x_map)
{
	int x;

	x = 0;
	while(x <= x_map)
	{
		if (str[x] == '1')
			map[x] = 1;
		if (str[x] == '0')
			map[x] = 0;
		if (x >= ft_strlen(str))
			map[x] = 0;
		x++;
	}
}

void	free_map(int **tab, int x, int y)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < y - 1)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_tab(void)
{
	int x_map = 23;
	int y_map = 10;
	char *str = ft_strdup("111111000001111");
	char *str2 = ft_strdup("0011000001111");
	int	**map;
	int i;
	
	i = 0;
	map = (int **)malloc((y_map - 1) * sizeof(int*));
	while (i < y_map)
	{
		map[i] = (int *)malloc(x_map * sizeof(int));
		ft_ligne(map[i], str2, x_map);
		i++;
	}
	afficherTableau(map, y_map, x_map);
	free_map(map, x_map, y_map);
}



int		main(void)
{
	ft_tab();
	return 1;
}