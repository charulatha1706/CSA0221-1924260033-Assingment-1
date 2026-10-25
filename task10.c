#include <stdio.h>
#include <limits.h>

int main(void)
{
    int sizes[] = {4000, 60000, 800000};
    int i, j;

    printf("Data type sizes and ranges:\n");
    printf("sizeof(int) = %lu bytes\n",
           (unsigned long)sizeof(int));
    printf("sizeof(long) = %lu bytes\n",
           (unsigned long)sizeof(long));
    printf("sizeof(long long) = %lu bytes\n",
           (unsigned long)sizeof(long long));
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    for (i = 0; i < 3; i++)
    {
        int n = sizes[i];
        float float_total = 0.0f;
        long long paise_total = 0;

        for (j = 0; j < n; j++)
        {
            float_total += 500.0f;
            paise_total += 50000LL;
        }

        printf("\nHouseholds = %d\n", n);
        printf("Float total = %.2f\n", float_total);
        printf("Integer-paise total = Rs %lld.%02lld\n",
               paise_total / 100,
               paise_total % 100);
        printf("Difference = Rs %.2f\n",
               (double)float_total -
               (double)paise_total / 100.0);
    }

    return 0;
}
