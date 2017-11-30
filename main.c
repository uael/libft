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
	ft_putf(1, "0: %d\n", ft_lst_at(lst, 0)->val);
	ft_putf(1, "1: %d\n", ft_lst_at(lst, 1)->val);
	ft_putf(1, "2: %d\n", ft_lst_at(lst, 2)->val);
	ft_putf(1, "3: %d\n", ft_lst_at(lst, 3)->val);
	ft_putf(1, "4: %d\n", ft_lst_at(lst, 4)->val);
	ft_putf(1, "5: %d\n", ft_lst_at(lst, 5)->val);
	ft_putf(1, "5: %d\n", ft_lst_rat(lst, 0)->val);
	ft_putf(1, "4: %d\n", ft_lst_rat(lst, 1)->val);
	ft_putf(1, "3: %d\n", ft_lst_rat(lst, 2)->val);
	ft_putf(1, "2: %d\n", ft_lst_rat(lst, 3)->val);
	ft_putf(1, "1: %d\n", ft_lst_rat(lst, 4)->val);
	ft_putf(1, "0: %d\n", ft_lst_rat(lst, 5)->val);
	return 0;
}