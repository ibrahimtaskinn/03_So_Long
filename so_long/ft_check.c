/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaskin <itaskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:24:29 by itaskin           #+#    #+#             */
/*   Updated: 2022/06/02 13:22:51 by itaskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_2(char **map, int a, int x_m, int y_m)
{
	int	b;

	b = 0;
	while (b < x_m && a < y_m)
	{
		if (a == 0 || a == (y_m - 1))
		{
			if (map[a][b] != '1')
				return (0);
		}
		if (b == 0 || b == (x_m - 1))
		{
			if (map[a][b] != '1')
				return (0);
		}
		b++;
	}
	return (1);
}

int	ft_check_map(char **map, int x_m, int y_m)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	while (b < x_m && a < y_m)
	{
		while (map[a][b] != '\0')
			b++;
		if ((b - 1) != x_m)
		{
			ft_printf("\033[2K\r\033[0;31mError\nMap Uygun Değil\n");
			return (0);
		}
		c = ft_check_map_2(map, a, x_m, y_m);
		if (c == 0)
		{
			ft_printf("\033[2K\r\033[0;31mError\nMap Duvarlarla Çevrili Değil\n");
			return (0);
		}
		b = 0;
		a++;
	}
	return (1);
}

int	ft_check_item_2(struct s_elements *g, int a, int b)
{
	if (g->map[a][b] == 'P')
	{
		g->p_c++;
		g->p_x = b;
		g->p_y = a;
	}
	if (g->map[a][b] == 'C')
		g->c_c++;
	if (g->map[a][b] == 'E')
		g->d_c++;
	return (0);
}

int	ft_check_item(struct s_elements *g)
{
	int	a;
	int	b;

	g->p_c = 0;
	g->c_c = 0;
	g->d_c = 0;
	a = 0;
	b = 0;
	while (b < g->x_m && a < g->y_m)
	{
		while (g->map[a][b] != '\0')
		{
			ft_check_item_2(g, a, b);
			b++;
		}
		b = 0;
		a++;
	}
	if (g->p_c != 1 || g->c_c < 1 || g->d_c < 1)
	{
		ft_printf("\033[2K\r\033[0;31mError\nMap Bileşenleri Eksik\n");
		return (0);
	}
	return (1);
}
