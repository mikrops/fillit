/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 10:59:10 by dheidenr          #+#    #+#             */
/*   Updated: 2019/02/10 10:59:14 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*str_to_no_slash_n(char *str1)
{
	size_t	i;
	size_t	length;
	char	*str2;
	char	*tmpstr2;

	i = 0;
	length = 0;
	while(str1[i++])
		if (str1[i] == '\n')
			length++;
	str2 = ft_strnew(ft_strlen(str1) - length);
	tmpstr2 = str2;
	while(*str1)
	{
		if (*str1 != '\n')
		{
			*str2 = *str1;
			str2++;
		}
		str1++;
	}
	return (tmpstr2);
}

void	width_num_to_xy(int width, int num, int *x, int *y)
{
	*x = num % width;
	*y = num / width;
}

void 	clear_map13(char map[13][13])
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while(i < 13)
	{
		while (j < 13)
		{
			map[i][j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
}

int 	is_xy_side_map_of_ch(int s, int x, int y, char m[13][13], char c, int b)
{
	if ((x >= s || y >= s || x < 0 || y < 0) ||
		(b && m[x][y] != '\0') || (!b && m[x][y] != c))
		return (0);
	return (1);
}

int		is_tetrim_in_map(int side,int num, int t[26][9], char map[13][13], int pos, int b)
{
	int 	x = 0;
	int 	y = 0;
	int		j = 0;
	int 	offset_x = 0;
	int 	offset_y = 0;

	width_num_to_xy(side, pos, &offset_x, &offset_y);
	if (t[num][0] == -1)
		return (0);
	while(j !=8)
	{
		x = t[num][j] + offset_x;
		j++;
		y = t[num][j] + offset_y;
		j++;
		if (!(is_xy_side_map_of_ch(side, x, y, map, t[num][8], b)))
			return (0);
	}
	return (1);
}

int		tetrim_to_map(int side, int num,int tetrim[26][9], char map[13][13], int pos, int b)
{
	int		j;
	int		x;
	int 	y;
	int 	offset_x = 0;
	int 	offset_y = 0;

	x = 0;
	y = 0;
	j = 0;
	if (!is_tetrim_in_map(side, num, tetrim, map, pos, b))
		return (0);
	width_num_to_xy(side, pos, &offset_x, &offset_y);
	while(j !=8)
	{
		x = tetrim[num][j] + offset_x;
		j++;
		y = tetrim[num][j] + offset_y;
		j++;
		if (b)
			map[x][y] = (unsigned char)tetrim[num][8];
		else
			map[x][y] = '\0';
	}
	return (1);
}

/*
** Поиск возможной нулевой позиции первой координаты тетримины
** Если начальная позиция тетримины не может уложится в нулевую позицию,
 * значит возвращается значение 1, иначе ноль.
 */
int		null_pos_x_tetrim(int num, int tetrim[26][9])
{
	int		j;
	int		x;
	int		one_x;

	one_x = tetrim[num][0];
	j = 0;
	while(j !=8)
	{
		x = tetrim[num][j];
		j++;
		j++;
		if (x < one_x)
			return (1);
	}
	return (0);
}

void	tetrim_to_null_position(int tetrim[26][9])
{
	int		i = 0;
	int 	j = 0;
	int		one_x = 0;
	int 	offsetx;
	int 	offsety;

	while(i < 26)
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

void	ft_no_slash_str_to_ttr(char *in_str, int t[26][9], size_t p, int x, int y)
{
	int 	i;
	int 	j;
	size_t	length;

	length = ft_strlen(in_str);
	i = -1;
	while(!(j = 0) && (++i < 26))
		while(j < 9)
		{
			if (p == length && (t[i][j++] = -1))
				continue ;
			if (j == 8 && (t[i][j] = 'A' + i))
				break;
			while(*in_str != '\0' && (p = p + 1))
				if (*in_str++ == '#')
					break;
			if (p == length && (t[i][j++] = -1))
				continue ;
			width_num_to_xy(4, p - 1, &x, &y);
			y = y % 4;
			t[i][j] = (j % 2 == 0) ? x : y;
			j++;
			t[i][j] = (j % 2 == 0) ? x : y;
			t[i][j++] = (p == length) ? -1 : t[i][j];
		}
}

char	*map13_to_str(char map[13][13], int side)
{
	int i;
	int j;
	char *str;
	char tmp[2] = "0\0";

	i = -1;
	j = -1;
	str = ft_memalloc(1);
	while(++i < side)
	{
		while(++j < side)
		{
			if (map[j][i] == '\0')
				str = ft_strjoin(str, ".");
			else
			{
				tmp[0] = map[j][i];
				str = ft_strjoin(str, tmp);
			}
		}
		j = -1;
		str = ft_strjoin(str, "\n");
	}
	return (str);
}

int 	w_tetrim_to_map(int side, int num, int t[26][9], char map[13][13])
{
	int 	poss;

	poss = 0;
	if (t[num][0] == -1)
		return (1);
	while (poss < side * side)
	{
		if (tetrim_to_map(side, num, t, map, poss, 1))
		{
			if (w_tetrim_to_map(side, num + 1, t, map))
				return (1);
		}
		tetrim_to_map(side, num, t, map, poss, 0);
		poss++;
	}
	return (0);
}



char *solution(char *str)
{
	int		t[26][9];
	char	map[13][13];
	int 	side = 4;

	ft_no_slash_str_to_ttr(str_to_no_slash_n(str), t, 0, 1, 1);
	tetrim_to_null_position(t);
	clear_map13(map);
	while (!w_tetrim_to_map(side++, 0, t, map))
		;
	return (map13_to_str(map, --side));
}