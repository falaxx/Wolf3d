/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:51:10 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/20 11:38:18 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_rect(t_s *s, SDL_Texture *txr, int high, int width)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (txr == s->tex->ground)
		SDL_SetRenderDrawColor(s->render, 180, 180, 180, 255);
	else if (txr == s->tex->player)
		SDL_SetRenderDrawColor(s->render, 20, 70, 20, 255);
	else if (txr == s->tex->wall)
		SDL_SetRenderDrawColor(s->render, 155, 30, 30, 255);
	else if (txr == s->tex->door)
		SDL_SetRenderDrawColor(s->render, 200, 200, 0, 255);
	SDL_SetRenderTarget(s->render, txr);
	while (y != high)
	{
		while (x != width)
		{
			SDL_RenderDrawPoint(s->render, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	SDL_SetRenderTarget(s->render, NULL);
}

void	ft_init_map(t_s *s)
{
	int x;
	int y;

	x = 0;
	y = 0;
	s->map = NULL;
	if (!(s->map = (t_map***)malloc(sizeof(t_map**) * (s->high))))
		ft_usage(-1, s);
	while (x < s->high)
	{
		s->map[x] = NULL;
		if (!(s->map[x] = (t_map**)malloc(sizeof(t_map*) * s->width)))
			ft_usage(-1, s);
		while (y < s->width)
		{
			s->map[x][y] = NULL;
			if (!(s->map[x][y] = (t_map *)malloc(sizeof(t_map))))
				ft_usage(-1, s);
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_init_struct3(t_s *s)
{
	if (!(s->tex->wall1 = (ft_tga_to_str("textures/wall_brick.tga", 1, s))))
		ft_usage(-1, s);
	if (!(s->tex->wall2 = (ft_tga_to_str("textures/wall_cobble.tga", 1, s))))
		ft_usage(-1, s);
	if (!(s->tex->wall3 = (ft_tga_to_str("textures/wall_dropper.tga", 1, s))))
		ft_usage(-1, s);
	if (!(s->tex->wall4 = (ft_tga_to_str("textures/wall_sticky.tga", 1, s))))
		ft_usage(-1, s);
	if (!(s->tex->wall5 = (ft_tga_to_str("textures/wall_door1.tga", 1, s))))
		ft_usage(-1, s);
}

void	ft_init_struct2(t_s *s)
{
	if (!(s->tex->wall = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPACE, SPACE)))
		ft_usage(-1, s);
	ft_draw_rect(s, s->tex->wall, SPACE, SPACE);
	if (!(s->tex->ground = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPACE, SPACE)))
		ft_usage(-1, s);
	ft_draw_rect(s, s->tex->ground, SPACE, SPACE);
	if (!(s->tex->door = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPACE, SPACE)))
		ft_usage(-1, s);
	ft_draw_rect(s, s->tex->door, SPACE, SPACE);
	if (!(s->tex->player = SDL_CreateTexture(s->render,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 4, 4)))
		ft_usage(-1, s);
	ft_draw_rect(s, s->tex->player, 4, 4);
	ft_init_struct3(s);
}

void	ft_init_struct(t_s *s)
{
	SDL_Init(SDL_INIT_VIDEO);
	if (!(s->window = SDL_CreateWindow("Wolf3d", 100, 100, WINDOW_WIDTH,
	WINDOW_HIGH, SDL_WINDOW_MAXIMIZED)))
		ft_usage(-1, s);
	if (!(s->render = SDL_CreateRenderer(s->window, -1, 0)))
		ft_usage(-1, s);
	s->pos->initplayer = 0;
	s->pos->eyehigh = 0;
	s->ray->texorcolor = 1;
	s->speed = SPEED;
	ft_init_struct2(s);
}
