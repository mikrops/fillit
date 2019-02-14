/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <dheidenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 23:14:51 by dheidenr          #+#    #+#             */
/*   Updated: 2019/02/14 16:31:12 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*out;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 10240 || validation(fd, &out) <= 0)
	{
		ft_putstr("error\n");
		close(fd);
		return (0);
	}
	close(fd);
	out = solution(out);
	ft_putstr(out);
	free(out);
	return (0);
}
