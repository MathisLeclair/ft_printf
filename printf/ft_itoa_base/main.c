char	*ft_itoa_base(int value, int base);

int		main()
{
	char *str;

	str = ft_itoa_base(-256, 2);
	printf("nombre = %s\n", str);
	return(0);
}