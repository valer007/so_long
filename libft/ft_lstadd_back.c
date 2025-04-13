/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:30:08 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/25 20:15:30 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstupdate_index(t_list **lst)
{
	t_list	*temp;
	t_list	*check;
	int		rank;

	temp = *lst;
	while (temp)
	{
		check = *lst;
		rank = 0;
		while (check)
		{
			if (check->content < temp->content)
				rank++;
			check = check->prev;
		}
		temp->index = rank;
		temp = temp->prev;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->index = 0;
		return ;
	}
	temp = *lst;
	while (temp->prev)
		temp = temp->prev;
	temp->prev = new;
	new->prev = NULL;
	ft_lstupdate_index(lst);
}
