/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:26:37 by ldoctori          #+#    #+#             */
/*   Updated: 2021/10/18 19:39:20 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		(*lst)->next = 0;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
