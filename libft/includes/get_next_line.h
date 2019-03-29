/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:59:26 by fmerding          #+#    #+#             */
/*   Updated: 2019/03/15 13:31:47 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000

int					get_next_line(const int fd, char **line);

typedef struct		s_gnlist
{
	char			*save;
	int				fd;
	struct s_gnlist	*next;
}					t_gnlist;

#endif
