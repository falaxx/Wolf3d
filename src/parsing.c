/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:39:25 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/19 17:55:02 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_tmp_to_char(char *tmp, char c)
{
	if (!tmp)
		return (0);
	while (tmp && tmp[0] != c)
		tmp++;
	tmp++;
	return (tmp);
}

void	ft_check_comma(char *block, t_s *s)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	if (block[i] < 48 || block[i] > 57)
		ft_usage(2, s);
	while (block[i] != '\0')
	{
		if (block[i] == ',' && block[i + 1] == ',')
			ft_usage(2, s);
		if (block[i] == ',')
			comma += 1;
		i++;
	}
	if (block[i] == ',' || comma != 4)
		ft_usage(2, s);
}

void	ft_parsing2(t_s *s, char **tab, int x, int y)
{
	char	*tmp;

	tmp = tab[x];
	ft_check_comma(tmp, s);
	s->map[x][y]->envi = atoi(tmp);
	tmp = ft_tmp_to_char(tmp, ',');
	s->map[x][y]->envi_sz = atoi(tmp);
	tmp = ft_tmp_to_char(tmp, ',');
	s->map[x][y]->roof = atoi(tmp);
	tmp = ft_tmp_to_char(tmp, ',');
	s->map[x][y]->roof_sz = atoi(tmp);
	tmp = ft_tmp_to_char(tmp, ',');
	s->map[x][y]->item = atoi(tmp);
	ft_memdel((void **)&tab[x]);
}

void	ft_parsing(t_s *s, char *av)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	**tab;

	if ((fd = open(av, O_RDONLY)) <= 0)
		ft_usage(-1, s);
	y = 0;
	tab = NULL;
	while (get_next_line(fd, &line))
	{
		x = -1;
		if (!(tab = ft_strsplit(line, ' ')))
			ft_usage(-1, s);
		while (++x < s->width)
			ft_parsing2(s, tab, x, y);
		ft_memdel((void **)&tab);
		y++;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	close(fd);
	ft_check_post_pars(s);
}
