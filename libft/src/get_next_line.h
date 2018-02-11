/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:58:47 by vholovin          #+#    #+#             */
/*   Updated: 2017/03/02 14:28:16 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"
# include <fcntl.h>

typedef struct		s_line
{
	int				fd;
	char			*buff_fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
