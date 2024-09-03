/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:57 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:49:10 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//main_functions
char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);
char	*ft_cut(char *stash);
char	*ft_save(char *stash);
char	*ft_save2(char *stash, size_t i, size_t len);

//aux_functions
char	*ft_free(char *s1);
//size_t	ft_strlen(const char *s);
int		ft_strchr_gnl(const char *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif