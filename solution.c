/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 10:59:10 by dheidenr          #+#    #+#             */
/*   Updated: 2019/02/12 16:18:02 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_side;
char g_map[13][13];

int		is_tetrim_in_map(int num, int tetrim[26][9], int pos, int b)
{
	int		x;
	int		y;
	int		j;
	int		offset_x;
	int		offset_y;

	j = 0;
	offset_x = 0;
	offset_y = 0;
	width_num_to_xy(g_side, pos, &offset_x, &offset_y);
	if (tetrim[num][0] == -1)
		return (0);
	while (j != 8)
	{
		x = tetrim[num][j] + offset_x;
		j++;
		y = tetrim[num][j] + offset_y;
		j++;
		if ((x >= g_side || y >= g_side ||
		x < 0 || y < 0) || (b && g_map[x][y] != '\0') ||
		(!b && g_map[x][y] != tetrim[num][8]))
			return (0);
	}
	return (1);
}

int		tetrim_to_map(int num, int tetrim[26][9], int pos, int b)
{
	int		j;
	int		x;
	int		y;
	int		offset_x;
	int		offset_y;

	j = 0;
	offset_x = 0;
	offset_y = 0;
	if (!is_tetrim_in_map(num, tetrim, pos, b))
		return (0);
	width_num_to_xy(g_side, pos, &offset_x, &offset_y);
	while (j != 8)
	{
		x = tetrim[num][j] + offset_x;
		j++;
		y = tetrim[num][j] + offset_y;
		j++;
		if (b)
			g_map[x][y] = (unsigned char)tetrim[num][8];
		else
			g_map[x][y] = '\0';
	}
	return (1);
}

char	*map13_to_str(void)
{
	int		i;
	int		j;
	char	*str;
	char	tmp[2];
	char	*p;

	i = -1;
	j = -1;
	str = ft_memalloc(1);
	ft_memset(str, 0, 1);
	while (++i < g_side)
	{
		while (++j < g_side)
		{
			p = str;
			tmp[0] = (g_map[j][i] == '\0') ? '.' : g_map[j][i];
			str = ft_strjoin(str, tmp);
			free(p);
		}
		j = -1;
		p = str;
		str = ft_strjoin(str, "\n");
		free(p);
	}
	return (str);
}

int		write_tetrim_to_map(int num, int tetrim[26][9])
{
	int		poss;

	poss = 0;
	if (tetrim[num][0] == -1)
		return (1);
	while (poss < g_side * g_side)
	{
		if (tetrim_to_map(num, tetrim, poss, 1))
		{
			if (write_tetrim_to_map(num + 1, tetrim))
				return (1);
		}
		tetrim_to_map(num, tetrim, poss, 0);
		poss++;
	}
	return (0);
}

char	*solution(char *str)
{
	int		t[26][9];
	int		tetrim_count;

	tetrim_count = 0;
	zeroing_map13_tetrim(g_map, t, no_slash_str_to_ttr(str, t, -1, 1));
	tetrim_to_null_position(t);
	while (t[tetrim_count][0] != -1)
		tetrim_count++;
	g_side = ft_sqrt(tetrim_count * 4);
	while (!write_tetrim_to_map(0, t))
		g_side++;
	free(str);
	return (map13_to_str());
}
