/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:29:13 by dheidenr          #+#    #+#             */
/*   Updated: 2019/02/12 18:29:18 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int num)
{
	int		i;
	int		sqrt;
	int		square;

	i = 0;
	sqrt = 0;
	while (++i <= num)
	{
		num = i;
		square = 0;
		while (++square <= i)
			if (square * square == i)
				return (square);
		sqrt = (square != 0) ? square : sqrt;
	}
	return (sqrt);
}

void	zeroing_map13_tetrim(char map[13][13], int t[26][9], int index_tetr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 13)
	{
		while (j < 13)
		{
			map[i][j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (index_tetr < 26)
	{
		while (i < 8)
			t[index_tetr][i++] = -1;
		t[index_tetr][i] = -1;
		i = 0;
		index_tetr++;
	}
}

int		null_pos_x_tetrim(int num, int tetrim[26][9])
{
	int		j;
	int		x;
	int		one_x;

	one_x = tetrim[num][0];
	j = 0;
	while (j != 8)
	{
		x = tetrim[num][j];
		j++;
		j++;
		if (x == one_x - 1)
			return (1);
		else if (x == one_x - 2)
			return (2);
	}
	return (0);
}

void	tetrim_to_null_position(int tetrim[26][9])
{
	int		i;
	int		j;
	int		one_x;
	int		offsetx;
	int		offsety;

	i = 0;
	j = 0;
	while (i < 26)
	{
		if (tetrim[i][0] == -1 || tetrim[i][1] == -1)
			return ;
		one_x = null_pos_x_tetrim(i, tetrim);
		offsetx = tetrim[i][0] - one_x;
		offsety = tetrim[i][1] - 0;
		while (j != 8)
		{
			tetrim[i][j] -= offsetx;
			j++;
			tetrim[i][j] -= offsety;
			j++;
		}
		j = 0;
		i++;
	}
}

int		no_slash_str_to_ttr(char *str, int tetrim[26][9], int p, int x)
{
	int		j;
	int		length;
	int		index_tetr;
	int		sharp_count;
	int		y;

	j = 0;
	index_tetr = 0;
	sharp_count = 0;
	length = ft_strlen(str);
	while (++p <= length)
		if (str[p] == '#')
		{
			width_num_to_xy(4, p, &x, &y);
			y = y % 4;
			tetrim[index_tetr][j++] = x;
			tetrim[index_tetr][j++] = y;
			if (++sharp_count == 4 && !(j = 0))
			{
				sharp_count = 0;
				tetrim[index_tetr][8] = 'A' + index_tetr;
				index_tetr++;
			}
		}
	return (index_tetr);
}
