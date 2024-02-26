#include <unistd.h>

void	ft_putnbr(int nb);

int	main(void)
{
	ft_putnbr(0003);
	write(1, " ", 1);
	ft_putnbr(13846294);
	write(1, " ", 1);
	ft_putnbr(-3947274);
	write(1, " ", 1);
	ft_putnbr(-2147483647);
	return (0);
}
