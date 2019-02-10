/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 22:51:38 by mmonahan          #+#    #+#             */
/*   Updated: 2019/02/10 00:30:59 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

int		check_and_read_tetrimin(int fd, char **line);
char	*solution(char *str);

#endif
