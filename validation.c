/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 22:28:56 by mmonahan          #+#    #+#             */
/*   Updated: 2019/02/13 19:05:47 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Проверяет содержимое buf на корректность (4х4, наличие символов '.' и '#',
**	а так же колличество '#')
**	Возвращает int:
**		1	-	корректные данные
**		0	-	не корректные данные
*/

int		check_text(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
		{
			if (buf[i] != '\n')
				return (0);
		}
		else if (buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	return (count != 4 ? 0 : 1);
}

/*
**	Заменяет в строке new первых 16 символов из old, игнорируя все '\n'.
**
**	Пар. 1	-	new, фексированая строка размером 17 заканчивающаяся на '\0'
**	Пар. 2	-	old, фексированая строка размером 22 заканчивающаяся на '\0'
*/

void	creat_str(char *new, char *old)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i != 16)
	{
		if (old[j] == '\n')
			j++;
		new[i++] = old[j++];
	}
}

/*
**	Проверяет строку str на корректность тетрамины, с помощью подсчета связей
**	по равой и нижней стороне.
**	Возвращает int:
**		1	-	корректная тетримина
**		0	-	не корректная тетримина
*/

int		check_str(char *str)
{
	int i;
	int link;

	i = 0;
	link = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] != '\0' && str[i + 1] == '#')
				link++;
			if (str[i + 2] != '\0' && str[i + 3] != '\0' && str[i + 4] == '#')
				link++;
		}
		i++;
	}
	return ((link == 3 || link == 4) ? 1 : 0);
}

/*
**	Проверяет колличество тетрамин в файле, от 1 до 26.
**
**	Пар. 1:	fd файловый дескриптор аргумента
**	Пар. 2:	line изменяемая строка
**	Возвращает int:
**		1	-	корректный файл
**		0	-	некорректный файл
**	Возвращает cтроку из файла без '\n', в случаей если файл корректный.
*/

int		validation(int fd, char **line)
{
	int		count;
	char	buf[22];
	char	str[17];
	char	*tmp;
	char	d;

	count = 0;
	*line = ft_memalloc(1);
	ft_memset(buf, 0, 22);
	while (read(fd, buf, 21))
	{
		ft_memset(str, 0, 17);
		if (!check_text(buf))
			return (0);
		creat_str(str, buf);
		if (!check_str(str))
			return (0);
		tmp = *line;
		*line = ft_strjoin(tmp, str);
		d = buf[20];
		free(tmp);
		ft_memset(buf, 0, 21);
		count++;
	}
	return (d != '\0' || count < 1 || count > 26 ? 0 : 1);
}
