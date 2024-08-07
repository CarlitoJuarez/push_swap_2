#include "../push_swap.h"

int len_of(node *root)
{
    int i;
    node *cur;

    i = 0;
    cur = root;
    while (cur)
    {
        i++;
        cur = cur->next;
    }
    return (i);
}

node *find_max(node *root)
{
    node *cur;
    node *max;

    cur = root;
    max = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->val > max->val)
            max = cur;
        cur = cur->next;
    }
    return (max);
}

node *find_min(node *root)
{
    node *cur;
    node *min;

    cur = root;
    min = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->val < min->val)
            min = cur;
        cur = cur->next;
    }
    return (min);
}

node *find_cheapest(node *root)
{
    node *cur;
    node *min;

    cur = root;
    min = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->price < min->price)
            min = cur;
        cur = cur->next;
    }
    return (min);
}

void	send_a_up(node **root_a, node **root_b, node *target, int pos)
{
	if (target->position < (len_of(*root_b) / 2 + 1))
	{
		while (pos && target->position)
		{
			exec_rotate(root_a);
			exec_rotate(root_b);
			ft_printf("rr\n");
			pos--;
			target->position--;
		}
		while (target->position)
		{
			exec_rotate(root_b);
			ft_printf("ra\n");
			target->position--;
		}
	}
	else
	{
		while (target->position != len_of(*root_b))
		{
			exec_rrotate(root_b);
			ft_printf("rra\n");
			target->position++;
		}
	}
	while (pos)
	{
		exec_rotate(root_a);
		ft_printf("rb\n");
		pos--;
	}
}

void	send_a_down(node **root_a, node **root_b, node *target, int pos)
{
	if (target->position > (len_of(*root_b) / 2 + 1))
	{
		while (pos && pos != len_of(*root_a) && target->position != len_of(*root_b))
		{
			exec_rrotate(root_a);
			exec_rrotate(root_b);
			ft_printf("rrr\n");
			pos++;
			target->position++;
		}
		while (target->position != len_of(*root_b))
		{
			exec_rrotate(root_b);
			ft_printf("rra\n");
			target->position++;
		}
	}
	else 
	{
		while (target->position)
		{
			exec_rotate(root_b);
			ft_printf("ra\n");
			target->position--;
		}
	}
	while (pos && pos != len_of(*root_a))
	{
		exec_rrotate(root_a);
		ft_printf("rrb\n");
		pos++;
	}
}

void	bring_to_start(node **root_a, node **root_b)
{
	int len;
	int pos;
	node *cheapest;
	node *target;

	cheapest = find_cheapest(*root_a);
	target = cheapest->target;
	len = len_of(*root_a);
	pos = cheapest->position;
	// 3 5 22 24
	// 6 9 21
	if (pos < (len / 2) + 1)
		send_a_up(root_a, root_b, target, pos);
	else
		send_a_down(root_a, root_b, target, pos);
}

long ft_atoi(char *s)
{
	size_t i;
	size_t res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		i++;
	}
	while (*(s + i))
	{
		res = res * 10 + (*(s + i) - '0');
		i++;
	}
	return (res * sign);
}