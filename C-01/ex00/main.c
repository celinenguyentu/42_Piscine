#include <stdio.h> 

void	ft_ft(int *nbr);

int main(void)
{
	int	*ptr;
	int	n;

	n = 18;
	ptr = &n;
	printf("Before ft_ft : n = %d\n", n);
	ft_ft(ptr);
	printf("After ft_ft : n = %d\n", n);
	return (0);
}
