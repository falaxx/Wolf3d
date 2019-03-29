/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:02:53 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/20 11:46:51 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_s *s)
{
	s->pos = NULL;
	s->tex = NULL;
	s->ray = NULL;
	s->n1 = NULL;
	if (!(s->pos = (t_pos*)malloc(sizeof(t_pos))))
		ft_usage(-1, s);
	if (!(s->tex = (t_tex*)malloc(sizeof(t_tex))))
		ft_usage(-1, s);
	if (!(s->ray = (t_ray*)malloc(sizeof(t_ray))))
		ft_usage(-1, s);
	if (!(s->n1 = (t_n1*)malloc(sizeof(t_n1))))
		ft_usage(-1, s);
	s->tex->wall = NULL;
	s->tex->ground = NULL;
	s->tex->door = NULL;
	s->tex->player = NULL;
	s->tex->wall1 = NULL;
	s->tex->wall2 = NULL;
	s->tex->wall3 = NULL;
	s->tex->wall4 = NULL;
	s->tex->wall5 = NULL;
	s->window = NULL;
	s->render = NULL;
}

int		main(int ac, char **av)
{
	t_s s;

	if (ac != 2)
		ft_usage(1, NULL);
	if (ft_strcmp(av[1], "maps/first_map.txt"))
		ft_usage(1, NULL);
	s.high = 0;
	s.width = 0;
	ft_init(&s);
	ft_check(&s, av[1]);
	ft_init_map(&s);
	ft_parsing(&s, av[1]);
	ft_init_struct(&s);
	ft_display(&s);
	return (0);
}
