#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

typedef struct node
{
    char            stack;
    int             val;
    int             up;
    int             position;
    int             price;

    struct node     *next;
    struct node     *prev;

    struct node     *target;
} node;


void    print_it(node *root);

// Basic helper

void    free_set(char **set, char **argv);
void    free_list(node *root);
void	bring_to_start(node **root_a, node **root_b);


void    push_normal(node **cur_a, node **cur_b, node **buf);
void    a_empty(node **cur_a, node **cur_b);
void    b_only_one(node **cur_a, node **cur_b);

int     is_space(char c);
int     len_of(node *root);
int     comp_str(char *s1, char *s2);
int     valid_input(char **argv);
int     is_sorted(node *root);
int     in_range(char **argv);
int     duplicates(node *root);

long    ft_atoi(char *s);

node    *find_max(node *root);
node    *find_min(node *root);
node    *find_cheapest(node *root);

// Init Node

void    set_pos(node *root);
void    set_target_2(node *root_a, node *root_b);
void    set_price_b(node *root_a, node *root_b);

// Algos

void    exec_algo(node **root_a, node **root_b);
void    three_nodes(node **root);
void    rev_three_nodes(node **root);

// Instructions

void    exec_swap(node **root);
void    exec_push(node **root_a, node **root_b);
void    exec_rotate(node **root);
void    exec_rrotate(node **root);

// Push Swap

void    push_swap(node **root);

// FT_PRINTF

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putaddress(void *p);
int		ft_puthexa(unsigned int n, const char c);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned long n);

char	*ft_strchr(const char *s, int c);

#endif