/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:00:00 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/18 22:00:01 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

static int	cmp_data(void *data1, void *data2)
{
	int		i;
	char	*d1;
	char	*d2;

	d1 = (char *)data1;
	d2 = (char *)data2;
	i = 0;
	while (d1[i] && d2[i])
	{
		if (d1[i] != d2[i])
			return (1);
		i++;
	}
	if (d1[i] != d2[i])
		return (1);
	return (0);
}

static void	list_remove_if_helper(t_list *temp, int (*cmp)(void *, void *))
{
	while (temp)
	{
		if (!cmp(temp->content, data_ref))
		{
			prev->next = temp->next;
			free(temp->content);
			free(temp);
			temp = *begin_list;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(void *, void *))
{
	t_list	*temp;
	t_list	*next_head;
	t_list	*prev;

	if (!begin_list || !*begin_list || !data_ref || !cmp)
		return ;
	temp = *begin_list;
	next_head = (*begin_list)->next;
	if (!cmp(temp->content, data_ref))
	{
		free(temp->content);
		free(temp);
		*begin_list = next_head;
		temp = *begin_list;
	}
	prev = temp;
	temp = temp->next;
	list_remove_if_helper(temp, (*cmp));
}
