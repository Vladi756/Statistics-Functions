#include <stdlib.h>
#include <math.h>


float mean(int x, float array[]);
float median(int x, float array[]);
float standardDev(int x, float array[]);
float kurtosis(int x, float array[]);

float mean(int x, float array[])
{
    float sum = 0;
    int i;
    for(i = 0; i < x; i++)
        sum += array[i];
    return(sum / x);
}

float median(int n, float array[])
{
    int compare (const void * a, const void * b)
    {
      float fa = *(const float *)a;
      float fb = *(const float *)b;
      return (fa > fb) - (fa < fb);
    }

    qsort(array, n, sizeof(float), compare);

    if(n%2==0)
        return((array[n/2] + array[n/2 - 1]) / 2.0);
    else
        return array[n/2];
}

float standardDev(int x, float array[])
{
    float variance = 0.0;
    int i;

    for (i = 0; i < x; ++i)
        variance += pow(array[i] - mean(x, array), 2);

    variance /= x;
    return sqrt(variance);

}

float kurtosis(int x, float array[])
{
    int i;
    float kurt;
    for(i = 0; i < x; i++)
        kurt += pow((array[i] - mean(x, array))/standardDev(x,array), 4)/x;

    return kurt;
}
