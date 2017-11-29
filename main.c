#include <libft.h>
#include <libft/ds/lst.h>

int main(void)
{
	t_lst slst;
	t_lst *lst;

	lst = ft_lst_ctor(&slst);
	ft_lst_push(lst, (void *) 0);
	ft_lst_push(lst, (void *) 1);
	ft_lst_push(lst, (void *) 2);
	ft_lst_push(lst, (void *) 3);
	ft_lst_push(lst, (void *) 4);
	ft_lst_push(lst, (void *) 5);
	ft_putf(1, "0: %d\n", ft_lst_front(lst)->val);
	ft_putf(1, "1: %d\n", ft_lst_front(lst)->next->val);
	ft_putf(1, "2: %d\n", ft_lst_front(lst)->next->next->val);
	ft_putf(1, "3: %d\n", ft_lst_front(lst)->next->next->next->val);
	ft_putf(1, "4: %d\n", ft_lst_front(lst)->next->next->next->next->val);
	ft_putf(1, "5: %d\n", ft_lst_front(lst)->next->next->next->next->next->val);
	ft_putf(1, "5: %d\n", ft_lst_back(lst)->val);
	ft_putf(1, "4: %d\n", ft_lst_back(lst)->prev->val);
	ft_putf(1, "3: %d\n", ft_lst_back(lst)->prev->prev->val);
	ft_putf(1, "2: %d\n", ft_lst_back(lst)->prev->prev->prev->val);
	ft_putf(1, "1: %d\n", ft_lst_back(lst)->prev->prev->prev->prev->val);
	ft_putf(1, "0: %d\n", ft_lst_back(lst)->prev->prev->prev->prev->prev->val);
	return 0;
}