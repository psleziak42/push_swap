#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define	INT_MAX	2147483647
#define INT_MIN	-2147483648

struct s_node
{
	int	value;
	struct s_node *next;
};

/*struct s_push
{
	int index;
	int *a;
}*/


void	ft_putchar(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	ft_print_list(struct s_node **head)
{
	struct s_node *temp;
	int i;


	if (!*head)
		return ;
	i = 0;
	temp = *head;
	while (temp->next)
	{
		i++;
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	i++;
	printf("%d.", temp->value);
	printf("\n%d\n", i);
}

int		ft_list_size(struct s_node **head)
{
	struct s_node *temp;
	int	i;

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

void	ft_del_list(struct s_node **head)
{
	struct s_node	*temp;
	struct s_node	*following;

	temp = *head;
	//printf("%d\n", temp->value);
	while (temp)
	{
		following = temp->next;
		free(temp);
		temp = following;
	}
	temp = NULL;
	*head = temp;
	//printf("%s\n", (char *)temp);
}

struct	s_node	*ft_add_back(struct s_node **head, int	value)
{
	struct	s_node	*temp;

	temp = *head;
	if (!*head)
	{
		temp = malloc(sizeof(struct s_node));
		temp->value = value;
	//	printf("%d - ", temp->value);
		temp->next = NULL;
		*head = temp;
	}
	else
	{
		while(temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(struct s_node));
		temp = temp->next;
		temp->value = value;
		temp->next = NULL;
	}
	//printf("%d\n", temp->value);
	return (temp);
}

struct s_node *ft_last(struct s_node **head)
{
	struct s_node *temp;

	if (!*head)
		return (0);
	temp = *head;
	while (temp->next)
	{
		if (!temp->next)
			break;
		temp = temp->next;
	}
	//printf("%d\n", temp->value);
	return (temp);
}

void	ft_sa(struct s_node **head) // shift 1st and 2nd
{
	struct s_node *temp;
	int	a;
	int b;

	temp = *head;
	
	a = temp->value;
	b = temp->next->value;

	temp->value = b;
	temp->next->value = a;
	write(1, "sa\n", 3);
}

void	ft_sb(struct s_node **head)
{
	struct s_node *temp;
	int	a;
	int b;

	temp = *head;
	
	a = temp->value;
	b = temp->next->value;

	temp->value = b;
	temp->next->value = a;
	write(1, "sb\n", 3);
}

void	ft_ss(struct s_node **head_a, struct s_node **head_b) // tutaj jest zle bo wydrukuje 3 instrukcje zaiast 1;
{
	ft_sa(head_a);
	ft_sa(head_b);
	write(1, "ss\n", 3);
}

void	ft_pa(struct s_node **head_a, struct s_node **head_b)
{
	struct s_node *temp_a;
	struct s_node *temp_b;

	if (*head_b == NULL)
	{
		write(1, "paNULL\n", 7);
		return ;
	}
	temp_a = *head_a;
	temp_b = *head_b;

	*head_b = temp_b->next;
	temp_b->next= temp_a;
	*head_a = temp_b;
	write(1, "pa\n", 3);
}

void	ft_pb(struct s_node **head_a, struct s_node **head_b) // moze byc zle
{
	struct s_node *temp_a;
	struct s_node *temp_b;

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

void	ft_ra(struct s_node	**head) // 1st becomes last
{
	struct s_node *temp;
	struct s_node *last;

	last = ft_last(head);
	temp = *head;

	last->next = temp;
	*head = temp->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(struct s_node **head_b)
{
	struct s_node	*temp;
	struct s_node	*last;

	temp = *head_b;
	last = ft_last(head_b);
	
	//printf("temp->value: %d\n", temp->value);

	last->next = temp;
	*head_b = temp->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(struct s_node **head_a, struct s_node **head_b)
{
	ft_ra(head_a);
	ft_ra(head_b);
	write(1, "rr\n", 3);
}

void	ft_rra(struct s_node **head) // last become first
{
	struct s_node *temp;
	struct s_node *last;

	last = ft_last(head);
	temp = *head;
	while (temp->next)
	{
		if (!temp->next->next)
			break;
		temp = temp->next;
	}
	last->next = *head;
	temp->next = NULL;
	*head = last; /// WAT DE FUCK?!?!?!?!
	write(1, "rra\n", 4);
}

void	ft_rrr(struct s_node **head_a, struct s_node **head_b)
{
	ft_rra(head_a);
	ft_rra(head_b);
	write(1, "rrr\n", 4);
}

int	ft_my_atoi(char *n)
{
	int	i;
	int	sign;
	long long int z;

	i = 0;
	z = 0;
	sign = 1;
	if (n[i] == ' ' || n[i] == '\t')
		i++;
	if (n[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
		{
			//printf("%c\n", n[i]);
			return (1);
		}
		z = z * 10 + n[i] - 48;
		i++;
	}
	if (z > INT_MAX || z < INT_MIN)
		return (1);
	return(sign * z);
}

int	ft_check(int ac, char **ab, struct s_node **head)
{
	int z;

	z = 1;
	if (ac < 2)
		return 1;
	ac = 1;
	while (ab[ac])
	{
		z = ft_my_atoi(ab[ac]);
		if (z == 1)
		{
			//printf("PAU\n");
			return (1);
		}
		else
			ft_add_back(head, z);
		ac++;
	}
	return (0);
}

int	ft_check_da_orda(struct s_node **head)
{
	struct s_node *temp;

	temp = *head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_check_da_orda_ab(struct s_node **head, struct s_node **head_b)
{
	struct s_node *temp;
	struct s_node *temp_b;

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

void	ft_sort_3(struct s_node **head, struct s_node **head_b) // do again for 3 and try for 5 tomorrow
{
	struct s_node *temp;
	struct s_node *temp_b;
	struct s_node *last;
	struct s_node *last_b;

	last = ft_last(head);
	last_b = ft_last(head_b);
	temp = *head;
	temp_b = *head_b;
	while (ft_check_da_orda(head) == 0 || *head_b != NULL)
	{
		//sleep(1);
		//printf("a\n");
		if (temp->value > last->value)
			ft_ra(head);
		else if (temp->value > temp->next->value)
		   ft_sa(head);
		else if (!(ft_check_da_orda(head))) // if not sorted a -> push b;
			ft_pb(head, head_b);
		else if (!(ft_check_da_orda(head_b)))
		{
			if (temp_b->value < last_b->value)
				ft_ra(head_b);
			else if (temp_b->value < temp_b->next->value)
				ft_sb(head_b);
			else
				ft_pa(head, head_b);
		}
		else if (ft_check_da_orda_ab(head, head_b))// if both sorted push b -> a // its missing to organize B stack!
			ft_pa(head, head_b);
		//ft_print_list(head);
		//ft_print_list(head_b);
		temp = *head;
		temp_b = *head_b;
		last = ft_last(head);
		last_b = ft_last(head_b);
	}
}

void	ft_sort(int *a, int list) // sortuje jedynie dla numerow pozytywnych, inaczej daje error // teraz trzeba wybrac 10 najmniejszych i wrzucac je do b i sortowac i pozniej kolejne 10 i sortowac i odeslac z powrotem
{
	int i;
	int j;
	int t;

	i = 0;
	j = 1;
	while (j < list)
	{
		if (a[i] > a[j])
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i = -1;
			j = 0; 
		}
		else
		{
			i++;
			j++;
		}
	}
	i = -1;
	/*while (++i < list)
		printf("%d -", a[i]);
	printf("\n");*/
}

int 	*ft_sort_array(struct s_node **head)
{
	struct s_node *temp;
	int *a;
	int i;
	int list;

	list = ft_list_size(head);
	a = malloc((list)*sizeof(int));
	if (!a)
		return 0;
	i = -1;
	temp = *head;
	while (temp->next)
	{
		a[++i] = temp->value;	
		temp = temp->next;
	}
	a[++i] = temp->value;
	ft_sort(a, list);
	return (a);
}

void	ft_chunk(struct s_node **head, struct s_node **head_b, int *a) // zrobione dla 100 i 500
{
	int i;
	int l;
	int k;
	int j;
	int q;
	struct s_node *temp;
	struct s_node *temp_b;
	temp = *head;
	l = ft_list_size(head); // tu jest blad dla minusowych numerow
	k = 0;
	q = 0;
	while (q < l)
		q++;
	if (l <= 100)
	{
		j = l/5;
		i = l/5 - 1;
	}
	if (l == 500)
	{
		j = 500/10;
		i = 49;
	}
	while (temp)
	{
		while (temp->value >= a[i]) // cos tu jest zle
		{
			k++;
			temp = temp->next;
			//printf("l - i = %d, list size: %d\n", l - i, ft_list_size(head));
			if (l - i == ft_list_size(head) + 1)
			{
				i = i + j;
				temp = *head;
			}
		}
		temp = *head;
		//printf("i: %d\n", i);
		//printf("l = i: %d\n", i);
		//printf("l - i: %d\n", l - i);
		if (k <= l/2)
		{
			while ((*head)->value > a[i])
				ft_ra(head);
			ft_pb(head, head_b);
		}
		else
		{
			while (temp->value != a[k])
				ft_rra(head);
			ft_pb(head, head_b);
		}
		printf("AAAAAAAAAAAAAAAAAAAAA\n");
		ft_print_list(head);
		write(1, "\n", 1);
		printf("BBBBBBBBBBBBBBBBBBBB\n");
		ft_print_list(head_b);
		temp = *head;
		k = 0;
	}
//	q = 99;
	/*while (q)
	{
		printf("%d-", a[q]);
		q--;
	}*/
	while (temp_b)
	{
		k = 0;
		temp_b = *head_b;
		q--;
		while (temp_b->value != a[q])
		{
			k++;
			temp_b = temp_b->next;
		}
		temp_b = *head_b;
		if (k <= l/2)
		{
			//printf("aq w k %d\n", a[q]);
			while ((*head_b)->value < a[q])
				ft_rb(head_b);
			ft_pa(head, head_b);
		}
		else
		{
			while ((*head_b)->value < a[q])
			{
				//printf("aqaqaqaqaq %d\n", a[q]);
				ft_rra(head_b);
			}
			ft_pa(head, head_b);
		}
		printf("aaaaaaaaaaaa\n");
		ft_print_list(head);
		write(1, "\n", 1);
		printf("bbbbbbbbbbbbbbb\n");	
		ft_print_list(head_b);
		printf("ugabuga\n");
		temp_b = *head_b;
		if (*head == NULL)
			break;
	}
}


int	main(int argv, char **argc)
{
	struct s_node *head;
	struct s_node *head_b;
	int	i;

	head = NULL;
	head_b = NULL;
	if (ft_check(argv, argc, &head) == 1)
	{
		write(1, "Error\n", 6);
		ft_del_list(&head);
		return 1;
	}
	printf("ARRAY\n");
	//ft_sort_array(&head);
	ft_chunk(&head, &head_b, ft_sort_array(&head));
	//printf("LIST\n");
	//ft_print_list(&head);
	/*ft_sort_3(&head, &head_b);
	ft_print_list(&head);
	ft_print_list(&head_b);*/
	//ft_sort_5(&head, &head_b);
}
