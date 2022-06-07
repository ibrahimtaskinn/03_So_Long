/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaskin <itaskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:41:53 by itaskin           #+#    #+#             */
/*   Updated: 2022/05/26 15:41:57 by itaskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include "ft_printf/ft_printf.h"
# include <string.h>

# define EVENT_W 13
# define EVENT_A 0
# define EVENT_S 1
# define EVENT_D 2

/* ****************
x_m = x_max
y_m = y_max
c_c = coin_count
d_c = door_count
p_c = player_count
p_x = player_x
p_y = player_y
p_xp = player_xpm
c_xp	=coin_xpm
d_xp = door_xpm
w_xp = wall_xpm
b_xp = bg_xpm
p_i = player_img
c_i = coin_img
d_i = door_img
w_i = wall_img
b_i = bg_img
m_p = mlx_ptr
w_p = win_ptr
*************** */

struct s_elements
{
	char	**map;
	int		x_m;
	int		y_m;
	int		c_c;
	int		d_c;
	int		p_c;
	int		p_x;
	int		p_y;
	char	*p_xp;
	char	*c_xp;
	char	*d_xp;
	char	*w_xp;
	char	*b_xp;
	char	*e_xp;
	void	*p_i;
	void	*c_i;
	void	*d_i;
	void	*w_i;
	void	*b_i;
	void	*e_i;
	void	*m_p;
	void	*w_p;
	int		h_s;
};

int		key(void);
void	ft_read_map_y(struct s_elements *g, int fd);
void	ft_read_map_x(struct s_elements *g, int fd);
void	ft_write_map(struct s_elements *g, int fd);
int		ft_check_map(char	**map, int x_m, int y_m);
int		ft_check_item(struct s_elements *g);
int		ft_draw_item(struct s_elements *g);
void	ft_move(struct s_elements *g, int y, int x);
void	ft_check_move(struct s_elements *g, int y, int x);
int		ft_key_check(int keycode, struct s_elements *g);
int		ft_draw_map(struct s_elements *g);
int		ft_check_map_2(char **map, int a, int x_m, int y_m);
int		ft_check_item_2(struct s_elements *g, int a, int b);
int		ft_drawing(struct s_elements *g, int a, int b);
int		map_arg_main(char *argv, struct s_elements *g);
int		draw_main(char *argv, struct s_elements *g);
char	*ft_strrchr(char *s, int c);
int		ft_check_arg(char *argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
