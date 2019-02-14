/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 22:51:38 by mmonahan          #+#    #+#             */
/*   Updated: 2019/02/12 19:00:35 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

int		validation(int fd, char **line);
char	*solution(char *str);

int		ft_sqrt(int num);
void	zeroing_map13_tetrim(char map[13][13], int t[26][9], int index_tetr);
int		null_pos_x_tetrim(int num, int tetrim[26][9]);
void	tetrim_to_null_position(int tetrim[26][9]);
int		no_slash_str_to_ttr(char *str, int tetrim[26][9], int p, int x);

int		tetrim_to_map(int num, int tetrim[26][9], int pos, int b);
int		write_tetrim_to_map(int num, int tetrim[26][9]);

void	width_num_to_xy(int width, int num, int *x, int *y);
#endif
