/*
 * Testing the performance of different fibonacci numbers calculation algorithms
 */

#include <stdio.h>
#include <time.h>

#define N 45

long fibonacci(int);

int main(void)
{
    int i;
    long l;
    clock_t begin, end;
    double time_spent;

    begin = clock();
    for (i = 0; i < N; i++)
    {
        l = fibonacci(i);
        printf("%4d %20ld\n", i, l);
    }
    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f sec\n", time_spent);

    return 0;
}

long fibonacci(int i)
{
    int k;
    long fib, a = 0L, b = 1L;
    
    if (i == 0)
    {
        fib = a;
    }
    else if (i == 1)
    {
        fib = b;
    }
    else
    {
        for(k = 2; k <=i; k++)
        {
            fib = a + b;
            a = b;
            b = fib;
        }
    }
    
    return fib;
}
