/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:00:40 by dheidenr          #+#    #+#             */
/*   Updated: 2019/02/12 19:00:42 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	width_num_to_xy(int width, int num, int *x, int *y)
{
	*x = num % width;
	*y = num / width;
}