#include "push_swap.h"

void	ft_sort(int *a, int list, struct s_h *h)
{
	ft_struct_init(h);
	while (h->j < list)
	{
		if (a[h->i] > a[h->j])
		{
			h->z = a[h->i];
			a[h->i] = a[h->j];
			a[h->j] = h->z;
			h->i = 0;
			h->j = 1;
		}
		else
		{
			h->i++;
			h->j++;
		}
	}
}

int	*ft_sort_array(struct s_n **head, struct s_h *h)
{
	struct s_n	*temp;
	int			*a;
	int			i;
	int			list;

	list = ft_list_size(head);
	a = malloc(list * sizeof(int));
	if (!a)
		return (0);
	i = -1;
	temp = *head;
	while (temp->next)
	{
		a[++i] = temp->value;
		temp = temp->next;
	}
	a[++i] = temp->value;
	ft_sort(a, list, h);
	return (a);
}

void	ab(struct s_n **h_a, struct s_n **h_b, struct s_h *h, int *a)
{
	h->temp = *h_a;
	while (h->temp)
	{
		while (h->temp->value > a[h->i])
		{
			h->z++;
			h->temp = h->temp->next;
			if (h->l - h->i == ft_list_size(h_a) + 1)
			{
				h->i = h->i + h->j;
				if (h->i > h->l)
					h->i = h->l - 1;
			}
		}
		while ((*h_a)->value > a[h->i])
		{
			if (h->z <= ft_list_size(h_a) / 2)
				ft_rx(h_a, 1);
			else
				ft_rrx(h_a, 1);
		}
		ft_pb(h_a, h_b);
		h->temp = *h_a;
		h->z = 0;
	}
}

void	ba(struct s_n **h_a, struct s_n **h_b, struct s_h *h, int *a)
{
	h->temp_b = *h_b;
	while (h->temp_b)
	{
		h->z = 0;
		h->temp_b = *h_b;
		h->l--;
		while (h->temp_b->value != a[h->l])
		{
			h->z++;
			h->temp_b = h->temp_b->next;
		}
		while ((*h_b)->value < a[h->l])
		{
			if (h->z <= ft_list_size(h_b) / 2)
				ft_rx(h_b, 2);
			else
				ft_rrx(h_b, 2);
		}
		ft_pa(h_a, h_b);
		h->temp_b = *h_b;
	}
}

void	cnk(struct s_n **h_a, struct s_n **h_b, struct s_h *h, int *a)
{
	h->l = ft_list_size(h_a);
	if (h->l <= 10)
	{
		ft_s3(h_a, h_b, h);
		return ;
	}
	else if (h->l > 10 && h->l <= 100)
	{
		h->j = h->l / 6;
		h->i = h->l / 5 - 1;
	}
	else if (h->l <= 500)
	{
		h->j = h->l / 13;
		h->i = h->l / 13 - 1;
	}
	else
	{
		h->j = h->l / 20;
		h->i = h->l / 20 - 1;
	}
	ab(h_a, h_b, h, a);
	ba(h_a, h_b, h, a);
}
