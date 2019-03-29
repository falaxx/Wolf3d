/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:02:53 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/20 11:40:30 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_memdelisation3(t_s *s)
{
	if (s->ray != NULL)
		ft_memdel((void **)&s->ray);
	if (s->n1 != NULL)
		ft_memdel((void **)&s->n1);
}

void	ft_memdelisation2(t_s *s)
{
	if (s->map != NULL)
		ft_memdel((void **)&s->map);
	if (s->tex->wall != NULL)
		SDL_DestroyTexture(s->tex->wall);
	if (s->tex->ground != NULL)
		SDL_DestroyTexture(s->tex->ground);
	if (s->tex->door != NULL)
		SDL_DestroyTexture(s->tex->door);
	if (s->tex->player != NULL)
		SDL_DestroyTexture(s->tex->player);
	if (s->tex->wall1 != NULL)
		ft_memdel((void **)&s->tex->wall1);
	if (s->tex->wall2 != NULL)
		ft_memdel((void **)&s->tex->wall2);
	if (s->tex->wall3 != NULL)
		ft_memdel((void **)&s->tex->wall3);
	if (s->tex->wall4 != NULL)
		ft_memdel((void **)&s->tex->wall4);
	if (s->tex->wall5 != NULL)
		ft_memdel((void **)&s->tex->wall5);
	if (s->pos != NULL)
		ft_memdel((void **)&s->pos);
	if (s->tex != NULL)
		ft_memdel((void **)&s->tex);
	ft_memdelisation3(s);
}

void	ft_memdelisation(t_s *s)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (s == NULL)
		return ;
	while (x < s->high && s->map != NULL)
	{
		while (y < s->width && s->map[x] != NULL)
		{
			if (s->map[x][y] != NULL)
				ft_memdel((void **)&s->map[x][y]);
			else
				break ;
			y++;
		}
		if (s->map[x] != NULL)
			ft_memdel((void **)&s->map[x]);
		else
			break ;
		y = 0;
		x++;
	}
	ft_memdelisation2(s);
}

void	ft_usage(int usage, t_s *s)
{
	if (usage == -1)
		ft_putstr("Error : Malloc failed\n");
	if (usage == 1)
		ft_putstr("Usage : ./Wolf3d maps/first_map.txt\n");
	if (usage == 2 || usage == 58)
		ft_putstr("Warning : Invalid file\n");
	if (usage == 3)
		ft_putstr("Warning : Invalid file (player error)\n");
	if (usage == 4)
		ft_putstr("Warning : Invalid file (surround map w/ wall)\n");
	if (usage == 5)
		ft_putstr("Warning : Invalid file (value not in range)\n");
	if (usage == 6)
		ft_putstr("Erreur de chargement de l'image");
	if (usage == 7)
		ft_putstr("Erreur de chargement de texture\n");
	if (s && usage != 58)
		ft_memdelisation(s);
	exit(0);
}
