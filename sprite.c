/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:23:31 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/10/01 12:15:17 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_init_sprite(t_params *param, int x, int y)
{
	if (param->sss.x == 0 && param->sss.y == 0)
	{
		param->sss.x = y;
		param->sss.y = x + 1;
	}
	else
	{
		dprintf(1, " --------------\n|   Map Error  |\n| multi sprite |\n --------------\n");
		exit(0);
	}
}

void	raycast_sprite_init(t_sprite *s, t_params *p)
{
	s->spritex = p->sss.x - p->pos.x;
	s->spritey = p->sss.y - p->pos.y;
	s->invdet = 1.0 / (p->plane.x * p->dir.y - p->dir.x
				* p->plane.y);
	s->transformx = s->invdet * (p->dir.y * s->spritex - p->dir.x
				* s->spritey);
	s->transformy = s->invdet * (-p->plane.y * s->spritex +
					p->plane.x * s->spritey);
	
	s->spritescreenx = (int)((p->size_x / 2) * (1 + s->transformx
					/ s->transformy));
	s->spriteheight = abs((int)(p->size_y / (s->transformy)));
	s->drawstarty = -s->spriteheight / 2 + p->size_y / 2;
	if (s->drawstarty < 0)
		s->drawstarty = 0;
	s->drawendy = s->spriteheight / 2 + p->size_y / 2;
	if (s->drawendy >= p->size_y)
		s->drawendy = p->size_y - 1;
	s->spritewidth = abs((int)(p->size_y / (s->transformy)));
	s->drawstartx = -s->spritewidth / 2 + s->spritescreenx;
	if (s->drawstartx < 0)
		s->drawstartx = 0;
	s->drawendx = s->spritewidth / 2 + s->spritescreenx;
	if (s->drawendx >= p->size_x)
		s->drawendx = p->size_x - 1;
	s->stripe = s->drawstartx;
}

void	raycast_sprite(t_params *p)
{
	t_sprite s;

	raycast_sprite_init(&s, p);
	while (s.stripe < s.drawendx)
	{
		s.texx = (int)(256 * (s.stripe - (-s.spritewidth / 2 + s.spritescreenx))
				* p->s.width / s.spritewidth) / 256;
		if (s.transformy > 0 && s.stripe > 0 && s.stripe < p->size_x
		&& s.transformy < p->zbuffer[s.stripe])
			s.y = s.drawstarty;
		while (s.y < s.drawendy)
		{
			s.d = s.y * 256 - p->size_y * 128 + s.spriteheight * 128;
			s.texy = ((s.d * p->s.height) / s.spriteheight) / 256;
			s.color = p->s.data[p->s.width * s.texy
					+ s.texx];
			if ((s.color & 0x00FFFFFF) != 0)
			{
				p->img.data[s.y * p->size_x + s.stripe] = s.color;
				
			}
			s.y++;
		}
		s.stripe++;
	}
}
