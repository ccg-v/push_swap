#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", strncmp(argv[1], argv[2], 2));
	if ((strncmp(argv[1], argv[2], 2)))
		printf("Los dos primeros caracteres son iguales\n");
	else
		printf("El segundo caracter es distinto\n");
}
