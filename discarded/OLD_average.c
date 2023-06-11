#include <stdio.h>
#include <limits.h>

double dynamic_average(int num) {
    static int count = 0;
    static double sum = 0.0;
    
    sum += num;
    count++;
    double average = sum / count;
    
    return average;
}

/*
int	main()
{
	int	i = 0;
	int num = INT_MAX;

	while (i < 500)
	{
		double average = dynamic_average(num);
		printf("Average so far: %f\n", average);
		num -= 1;
		i++;
	}
}
*/

int main() {
    int num;
    while (1) {
        printf("Enter an integer (or -1 to finish): ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        double average = dynamic_average(num);
        printf("Average so far: %f\n", average);
    }
    return 0;
}

