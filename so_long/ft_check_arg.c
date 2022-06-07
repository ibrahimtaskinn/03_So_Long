/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaskin <itaskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:09:46 by itaskin           #+#    #+#             */
/*   Updated: 2022/05/26 16:31:51 by itaskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	a1;
	unsigned char	a2;

	while (n-- > 0)
	{
		a1 = *(unsigned char *)s1++;
		a2 = *(unsigned char *)s2++;
		if (a1 != a2)
			return (a1 - a2);
		if (a1 == '\0')
			return (0);
	}
	return (0);
}

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

int	ft_check_arg(char *argv)
{
	char	*a;
	void	*b;
	int		fd;

	a = ".ber";
	b = ft_strrchr(argv, '.');
	fd = open(argv, O_RDONLY);
	if (a == NULL || ft_strncmp(a, b, 4) != 0 || fd == -1)
	{
		ft_printf("Geçersiz Arguman Girişi\n");
		return (0);
	}
	close(fd);
	return (1);
}
