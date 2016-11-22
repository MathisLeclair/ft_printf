int		ft_atoi_base(const char *str, int str_base);

int		main()
{
	int i;

	i = ft_atoi_base("-1fg0", 16);
	printf("i = %d\n", i);
	return (0);
}
