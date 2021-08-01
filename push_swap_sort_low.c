#include "push_swap.h"

int	ft_check_da_orda(struct s_n **head)
{
	struct s_n	*temp;

	temp = *head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_check_rev_orda(struct s_n **head, struct s_n **head_b)
{
	struct s_n	*temp;

	temp = *head;
	while (temp->next)
	{
		if (!(temp->value > temp->next->value))
			return (0);
		temp = temp->next;
	}
	while (ft_list_size(head) > 3)
		ft_pb(head, head_b);
	return (1);
}

int	ft_check_orda_ab(struct s_n **head, struct s_n **head_b)
{
	struct s_n	*temp;
	struct s_n	*temp_b;

	temp = *head;
	temp_b = *head_b;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	while (temp_b->next)
	{
		if (temp_b->value > temp_b->next->value)
			return (0);
		temp_b = temp_b->next;
	}
	return (1);
}

void	ft_s3i(struct s_n **head, struct s_n **head_b, struct s_h *h)
{
	h->last = ft_last(head);
	h->last_b = ft_last(head_b);
	h->temp = *head;
	h->temp_b = *head_b;
}

void	ft_s3(struct s_n **head, struct s_n **head_b, struct s_h *h)
{
	ft_s3i(head, head_b, h);
	if (ft_check_da_orda(head) == 1)
		return ;
	ft_check_rev_orda(head, head_b);
	while (ft_check_da_orda(head) == 0 || *head_b != NULL)
	{
		if (h->temp->value > h->last->value)
			ft_rx(head, 1);
		else if (h->temp->value > h->temp->next->value)
			ft_sx(head, 1);
		else if (!(ft_check_da_orda(head)))
			ft_pb(head, head_b);
		else if (!(ft_check_da_orda(head_b)))
		{
			if (h->temp_b->value < h->last_b->value)
				ft_rx(head_b, 1);
			else if (h->temp_b->value < h->temp_b->next->value)
				ft_sx(head_b, 2);
			else
				ft_pa(head, head_b);
		}
		else if (ft_check_orda_ab(head, head_b))
			ft_pa(head, head_b);
		ft_s3i(head, head_b, h);
	}
}
