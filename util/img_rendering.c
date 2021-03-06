/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:54:22 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/01 14:46:58 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render(t_app *app)
{
	if (app->win == NULL)
		return (0);
	render_background(&app->img, 0x00000000);
	draw(app);
	mlx_put_image_to_window(app->init, app->win, app->img.mlx_img, 0, 0);
	return (0);
}
