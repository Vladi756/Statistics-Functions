#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main()
{
    int n;
    int i;
    float numbers[100];

    printf("Enter number of elements:");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("\%fn", &numbers[i]);
    }

    printf("Mean = %.2f\n",mean(n, numbers));
    printf("Median = %.2f\n",median(n, numbers));
    printf("Standard Deviation = %.2f\n", standardDev(n, numbers));
    printf("Kurtosis = %.2f", kurtosis(n, numbers));

    return 0;
}
