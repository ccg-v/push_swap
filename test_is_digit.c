#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (*str)
    {
        i++;
        str++;
    }
    return (i);
}

static int	ft_is_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = ft_strlen(argv[i]);
		while (argv[i][j] == '-')
			j++;
		while (j < len)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
./
int main (int argc, char **argv)
{
    int result;
    
    result = ft_is_digit(argc, argv);
    printf("result is %d\n", result);
    return (0);
}
