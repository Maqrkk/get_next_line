/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mpeerdem <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 10:36:00 by mpeerdem      #+#    #+#                 */
/*   Updated: 2020/01/06 08:23:44 by mpeerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*
**	If the buffer size wasn't specified, set it to the default of 32.
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/*
**	The fdlist is a linked list that will hold the buffers that are being used.
*/

typedef struct		s_fdlist
{
	int				fd;
	char			*buf;
	struct s_fdlist	*next;
}					t_fdlist;

/*
**	get_next_line.c
*/

int					get_next_line(int fd, char **line);
int					read_line(int fd, char **line, char *buffer);
void				gnl_strjoin(char **s1, char *s2);
int					gnl_strlen(char *str);
void				gnl_strcpy(char *dst, char *src);

/*
**	get_next_line_utils.c
*/

int					gnl_strchr(char *str, char c);
void				shift_buffer(char *buffer, int n);
t_fdlist			*get_fdlist(int fd, t_fdlist **head);
void				*fdlist_clear(t_fdlist **head);
void				fdlist_remove(t_fdlist **head, int fd);

#endif
