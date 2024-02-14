void ft_putchar(char c);

void ft_print_top(int x)
{
	int colonnes;
	
	colonnes = 0;
	if (x >= 1)
	{
		ft_putchar('A');
		colonnes = colonnes + 1;
	}
	while (colonnes < x - 1)
	{
		ft_putchar('B');
		colonnes = colonnes + 1;
	}
	if (x >= 2)
	{
		ft_putchar('C');
		//colonnes = colonnes + 1;
	}
}

void ft_print_bottom(int x);
void ft_print_lateral(int x);

void rush04(int x, int y)
{
	int lignes;
	
	lignes = 0;
	if (y >= 1)
	{
		ft_print_top(x);
		lignes = lignes +1;
	}
	while (lignes < y - 1)
	{
		ft_print_lateral(x);
		lignes = lignes + 1;
	}
	if (y >= 2)
	{
		ft_print_bottom(x);
		//lignes = lignes + 1;
	}
}
