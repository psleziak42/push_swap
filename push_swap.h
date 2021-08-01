#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define	INT_MAX	2147483647
# define	INT_MIN	-2147483648

struct s_n
{
	int				value;
	struct s_n		*next;
};

struct	s_h
{
	int				i;
	int				j;
	int				l;
	int				sign;
	int				atoi;
	long long int	z;
	struct s_n		*temp;
	struct s_n		*temp_b;
	struct s_n		*last;
	struct s_n		*last_b;
};

void			ft_struct_init(struct s_h *h);
void			ft_print_list(struct s_n **head);
int				ft_list_size(struct s_n **head);
void			ft_del_list(struct s_n **head);
struct s_n		*ft_add_back(struct s_n **head, int value);
struct s_n		*ft_last(struct s_n **head);
void			ft_sx(struct s_n **head, int x);
void			ft_pa(struct s_n **head_a, struct s_n **head_b);
void			ft_pb(struct s_n **head_a, struct s_n **head_b);
void			ft_rx(struct s_n **head, int x);
void			ft_rrx(struct s_n **head, int x);
int				ft_my_atoi(char *n, struct s_n **head, struct s_h *h);
void			ft_exit(struct s_n **head);
int				ft_chck(int ac, char **ab, struct s_n **head, struct s_h *h);
int				ft_check_da_orda(struct s_n **head);
int				ft_check_rev_orda(struct s_n **head, struct s_n **head_b);
int				ft_check_orda_ab(struct s_n **head, struct s_n **head_b);
void			ft_s3i(struct s_n **head, struct s_n **head_b, struct s_h *h);
void			ft_s3(struct s_n **head, struct s_n **head_b, struct s_h *h);
void			ft_sort(int *a, int list, struct s_h *h);
int				*ft_sort_array(struct s_n **head, struct s_h *h);
void			ab(struct s_n **h_a, struct s_n **h_b, struct s_h *h, int *a);
void			ba(struct s_n **h_a, struct s_n **h_b, struct s_h *h, int *a);
void			cnk(struct s_n **h_a, struct s_n **h_b, struct s_h *h, int *a);

#endif
