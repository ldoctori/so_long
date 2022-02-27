/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:15:23 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/07 16:15:25 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(char **line, int fd);
int		ft_strlen_g(char	*str);
char	*ft_strjoin_g(char *str, char *buff);
char	*ft_strchr_g(char *str, char ch);
char	*ft_strndup_g(char *str, int len);

#endif
