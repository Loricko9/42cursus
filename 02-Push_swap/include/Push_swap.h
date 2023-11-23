/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:27:16 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/17 15:03:05 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_list
{
	int				nb;
	int				rank;
	int				mv_a;
	int				mv_b;
	struct s_list	*next;
	struct s_list	*prec;
}	t_list;

//Push_swap.c
void		ft_error(t_list *stack_a);
void		ft_ajust(t_list **stack_a, int size);

//get_lst.c
long long	ft_atoi(const char *nptr);
int			create_node(int i, int j, char **av, t_list **stack_a);
void		get_lst(char **av, t_list **stack_a);
void		get_rank(t_list *stack_a);
void		get_rank2(t_list **stack_a, t_list **temp, int *max);

//list_utils.c
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(int nb);
void		ft_lstadd_back(t_list **lst, t_list	*new);
t_list		*ft_lstlast(t_list *lst);
int			ft_free_lst(t_list *lst);

//check_av.c
int			check_line(char *str);
int			check_av(char **av);
int			check_double(t_list *stock);
int			check_order(t_list *stack_a);

//Sort.c
void		sab(t_list *stack, int a);
void		ss(t_list *stack_a, t_list *stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);

//Sort2.c
void		rab(t_list **stack, int a);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrab(t_list **stack, int a);
void		rrr(t_list **stack_a, t_list **stack_b);

//Sort3.c
void		pb2(t_list **stack_a, t_list **stack_b);
void		pa2(t_list **stack_a, t_list **stack_b);

//Swap.c
void		sort_2v(t_list *stack);
void		sort_3v(t_list **stack);
void		sort_3v2(t_list **stack, t_list *prec, t_list *next);
void		swap_ph1(t_list **stack_a, t_list **stack_b, int size, int tier1);
void		swap(t_list **stack_a, t_list **stack_b, int size);

//Swap2.c
int			min_rank(t_list *stack_a, int *rank);
void		little_swap(t_list **stack_a, t_list **stack_b, int size);
int			swap_ph1_move(t_list **stack_a, t_list **stack_b, int tier1,
				int tier2);
int			sort_prox(int size, int rank);
int			get_div(int size);

//Swap3.c
void		get_lowest_cost2(int mv_a, int mv_b, int *total);
void		get_lowest_cost(t_list *stack_b, int *mv_a, int *mv_b, int size);
void		swap_ph2(t_list **stack_a, t_list **stack_b);
void		do_swap(t_list **stack_a, t_list **stack_b, int mv_a, int mv_b);
void		do_swap2(t_list **stack_a, t_list **stack_b, int *mv_a, int *mv_b);

//Swap3_cost.c
int			cost_mv_b(t_list *stack_b, int size, int niv, int rank);
int			cost_mv_a(t_list *stack_a, int size, int rank);
int			cost_mv_a2(t_list *temp, int rank);
void		get_cost(t_list **stack_a, t_list **stack_b);
void		get_lowest_cost3(int *mv_a, int *mv_b, int *total);

//Swap3_cost_extrem.c
int			min(t_list *stack);
int			max(t_list *stack);
int			cost_mv_a_extremum(t_list *stack_a, int *mv, int rank, int size);

#endif
