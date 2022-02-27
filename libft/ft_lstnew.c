/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:18:32 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/20 09:06:52 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_elem;

	list_elem = malloc(sizeof(t_list));
	if (!list_elem)
		return (0);
	list_elem->content = content;
	list_elem->next = 0;
	return (list_elem);
}
