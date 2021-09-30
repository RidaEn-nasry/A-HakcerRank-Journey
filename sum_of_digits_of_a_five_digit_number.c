#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *sum_of_elements(int n, int *sum){
    *sum += (n % 10);
    if (n < 10)
        return sum;
    n /= 10;
    sum_of_elements(n, sum);
    return;
}

int main() {
	
    int n, sum;
    sum = 0;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    sum_of_elements(n, &sum);
    printf("%d\n", sum);
    return 0;
}
