#include "push_swap.h"

void	ft_struct_init(struct s_h *h)
{
	h->i = 0;
	h->j = 1;
	h->sign = 1;
	h->atoi = 0;
	h->z = 0;
	h->temp = NULL;
	h->temp_b = NULL;
	h->last = NULL;
	h->last_b = NULL;
}

void	ft_exit(struct s_n **head)
{
	ft_del_list(head);
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_my_atoi(char *n, struct s_n **head, struct s_h *h)
{
	ft_struct_init(h);
	if (n[h->i] == ' ' || (n[h->i] >= 9 && n[h->i] <= 13))
		h->i++;
	if (n[h->i] == '-')
	{
		h->sign = -1;
		h->i++;
	}
	while (n[h->i])
	{
		if (!(n[h->i] >= '0' && n[h->i] <= '9'))
			ft_exit(head);
		h->z = h->z * 10 + n[h->i] - 48;
		h->i++;
	}
	if (h->z > INT_MAX || h->z < INT_MIN)
		ft_exit(head);
	return (h->sign * h->z);
}

int	ft_chck(int ac, char **ab, struct s_n **head, struct s_h *h)
{
	struct s_n	*temp;

	ac = 1;
	while (ab[ac])
	{
		h->atoi = ft_my_atoi(ab[ac], head, h);
		temp = *head;
		while (temp)
		{
			if (temp->value == h->atoi)
				return (1);
			temp = temp->next;
		}
		ft_add_back(head, h->atoi);
		ac++;
	}
	return (0);
}

int	main(int argv, char **argc)
{
	struct s_n	*head;
	struct s_n	*head_b;
	struct s_h	h;

	ft_struct_init(&h);
	if (argv < 2)
		return (0);
	head = NULL;
	head_b = NULL;
	if (ft_chck(argv, argc, &head, &h) != 0)
	{
		write(1, "Error\n", 6);
		ft_del_list(&head);
		return (0);
	}
	cnk(&head, &head_b, &h, ft_sort_array(&head, &h));
	free(ft_sort_array(&head, &h));
	ft_del_list(&head);
	return (0);
}
