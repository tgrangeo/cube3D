/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:46:34 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/11/23 13:23:59 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void			ft_bitmap_image(t_bmp *bmp, int fd, t_img img)
{
	unsigned int	x;
	int				y;
	int				ble;
	unsigned char	color[3];

	y = bmp->bih.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < bmp->bih.width)
		{
			ble = img.data[x + y * bmp->bih.width];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

int				ft_save_bitmap(const char *filename, t_params params)
{
	t_bmp bmp;

	new_image(&params);
	ft_memcpy(&bmp.bfh.bitmap_type, "BM", 2);
	bmp.bfh.file_size = params.size_x *
							params.size_y * 4 + 54;
	bmp.bih.size_header = sizeof(bmp.bih);
	bmp.bih.width = params.size_x;
	bmp.bih.height = params.size_y;
	bmp.bih.planes = 1;
	bmp.bih.bit_count = 24;
	bmp.bih.compression = 0;
	bmp.bih.image_size = bmp.bfh.file_size;
	bmp.bih.ppm_x = 2;
	bmp.bih.ppm_y = 2;
	bmp.bih.clr_used = 0;
	bmp.bih.clr_important = 0;
	bmp.fd = open(filename, O_RDWR | O_CREAT, 0755);
	write(bmp.fd, &bmp.bfh, 14);
	write(bmp.fd, &bmp.bih, sizeof(bmp.bih));
	ft_bitmap_image(&bmp, bmp.fd, params.img);
	//dprintf(1, "zearhdfghgf,j\n");
	close(bmp.fd);
	return (0);
}