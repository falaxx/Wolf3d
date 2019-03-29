/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:28:44 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/19 18:00:37 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_display3(t_s *s)
{
	int		x;
	int		y;

	y = (s->pos->floaty + SPACE / 8) / SPACE;
	x = (s->pos->floatx + SPACE / 8) / SPACE;
	if (s->map[x][y]->envi == 1000
	|| s->map[x][y]->envi == 1001)
		s->map[x][y]->envi = 0;
}

void	ft_display2(t_s *s, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		ft_usage(42, s);
	if (event.key.keysym.scancode == SDL_SCANCODE_P)
		s->ray->texorcolor = s->ray->texorcolor == 0 ? 1 : 0;
	if (event.key.keysym.scancode == SDL_SCANCODE_W)
		ft_dir_player(s, 1);
	if (event.key.keysym.scancode == SDL_SCANCODE_S)
		ft_dir_player(s, 2);
	if (event.key.keysym.scancode == SDL_SCANCODE_D)
		ft_dir_player(s, 3);
	if (event.key.keysym.scancode == SDL_SCANCODE_A)
		ft_dir_player(s, 4);
	if (event.key.keysym.scancode == SDL_SCANCODE_E)
		ft_display3(s);
	if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		s->pos->dirplayer = (s->pos->dirplayer += 5) >= 360
		? 0 : s->pos->dirplayer;
	if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
		s->pos->dirplayer = (s->pos->dirplayer -= 5) < 0
		? 350 : s->pos->dirplayer;
}

void	ft_display(t_s *s)
{
	SDL_Event	event;
	int			i;

	i = 0;
	ft_draw_minimap(s);
	ft_rcasting(s);
	ft_draw_minimap(s);
	while (1)
	{
		if (event.type == SDL_QUIT)
			ft_usage(42, s);
		if (event.type == SDL_KEYDOWN)
			ft_display2(s, event);
		i = SDL_PollEvent(&event);
		if (i == 0)
		{
			ft_rcasting(s);
			ft_draw_minimap(s);
		}
	}
}
