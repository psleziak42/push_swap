#include "push_swap.h"

void	ft_print_list(struct s_n **head)
{
	struct s_n		*temp;
	int				i;

	if (!*head)
		return ;
	i = 0;
	temp = *head;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
}

int	ft_list_size(struct s_n **head)
{
	struct s_n	*temp;
	int			i;

	if (!*head)
		return (0);
	i = 0;
	temp = *head;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_del_list(struct s_n **head)
{
	struct s_n	*temp;
	struct s_n	*following;

	temp = *head;
	while (temp)
	{
		following = temp->next;
		free(temp);
		temp = following;
	}
	temp = NULL;
	*head = temp;
}

struct s_n	*ft_add_back(struct s_n **head, int value)
{
	struct s_n	*temp;

	temp = *head;
	if (!*head)
	{
		temp = malloc(sizeof(struct s_n));
		temp->value = value;
		temp->next = NULL;
		*head = temp;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(struct s_n));
		temp = temp->next;
		temp->value = value;
		temp->next = NULL;
	}
	return (temp);
}

struct s_n	*ft_last(struct s_n **head)
{
	struct s_n	*temp;

	if (!*head)
		return (0);
	temp = *head;
	while (temp->next)
	{
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (temp);
}
