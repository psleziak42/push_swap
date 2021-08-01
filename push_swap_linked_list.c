#include "push_swap.h"

void	ft_sx(struct s_n **head, int x)
{
	struct s_n	*temp;
	int			a;
	int			b;

	temp = *head;
	a = temp->value;
	b = temp->next->value;
	temp->value = b;
	temp->next->value = a;
	if (x == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ft_pa(struct s_n **head_a, struct s_n **head_b)
{
	struct s_n	*temp_a;
	struct s_n	*temp_b;

	if (*head_b == NULL)
	{
		write(1, "paNULL\n", 7);
		return ;
	}
	temp_a = *head_a;
	temp_b = *head_b;
	*head_b = temp_b->next;
	temp_b->next = temp_a;
	*head_a = temp_b;
	write (1, "pa\n", 3);
}

void	ft_pb(struct s_n **head_a, struct s_n **head_b)
{
	struct s_n	*temp_a;
	struct s_n	*temp_b;

	if (*head_a == NULL)
	{
		write(1, "pbNULL\n", 7);
		return ;
	}
	temp_a = *head_a;
	temp_b = *head_b;
	if (!head_b)
	{
		*head_b = temp_a;
		*head_a = temp_a->next;
		temp_a->next = NULL;
	}
	*head_a = temp_a->next;
	temp_a->next = temp_b;
	*head_b = temp_a;
	write(1, "pb\n", 3);
}

void	ft_rx(struct s_n	**head, int x)
{
	struct s_n	*temp;
	struct s_n	*last;

	last = ft_last(head);
	temp = *head;
	last->next = temp;
	*head = temp->next;
	temp->next = NULL;
	if (x == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	ft_rrx(struct s_n **head, int x)
{
	struct s_n	*temp;
	struct s_n	*last;

	last = ft_last(head);
	temp = *head;
	while (temp->next)
	{
		if (!temp->next->next)
			break ;
		temp = temp->next;
	}
	last->next = *head;
	temp->next = NULL;
	*head = last;
	if (x == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
