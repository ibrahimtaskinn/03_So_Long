/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaskin <itaskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:45:09 by itaskin           #+#    #+#             */
/*   Updated: 2022/05/26 14:45:19 by itaskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_item(struct s_elements *g)
{
	int		width;
	int		height;

	g->m_p = mlx_init();
	g->p_xp = "xpm/player_animation/1.xpm";
	g->c_xp = "xpm/coin_animation/1.xpm";
	g->b_xp = "xpm/bg.xpm";
	g->w_xp = "xpm/wall.xpm";
	g->d_xp = "xpm/door.xpm";
	g->e_xp = "xpm/enemy.xpm";
	g->p_i = mlx_xpm_file_to_image(g->m_p, g->p_xp, &width, &height);
	g->c_i = mlx_xpm_file_to_image(g->m_p, g->c_xp, &width, &height);
	g->b_i = mlx_xpm_file_to_image(g->m_p, g->b_xp, &width, &height);
	g->w_i = mlx_xpm_file_to_image(g->m_p, g->w_xp, &width, &height);
	g->d_i = mlx_xpm_file_to_image(g->m_p, g->d_xp, &width, &height);
	g->e_i = mlx_xpm_file_to_image(g->m_p, g->e_xp, &width, &height);
	return (0);
}

int	ft_drawing(struct s_elements *g, int a, int b)
{
	if (g->map[a][b] == '1')
		mlx_put_image_to_window(g->m_p, g->w_p, g->w_i, b * 50, a * 50);
	else if (g->map[a][b] == '0')
		mlx_put_image_to_window(g->m_p, g->w_p, g->b_i, b * 50, a * 50);
	else if (g->map[a][b] == 'P')
		mlx_put_image_to_window(g->m_p, g->w_p, g->p_i, b * 50, a * 50);
	else if (g->map[a][b] == 'C')
		mlx_put_image_to_window(g->m_p, g->w_p, g->c_i, b * 50, a * 50);
	else if (g->map[a][b] == 'E')
		mlx_put_image_to_window(g->m_p, g->w_p, g->d_i, b * 50, a * 50);
	else if (g->map[a][b] == 'N')
		mlx_put_image_to_window(g->m_p, g->w_p, g->e_i, b * 50, a * 50);
	return (0);
}

int	ft_draw_map(struct s_elements *g)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (b < g->x_m && a < g->y_m)
	{
		while (b < g->x_m && a < g->y_m)
		{
			ft_drawing (g, a, b);
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}
