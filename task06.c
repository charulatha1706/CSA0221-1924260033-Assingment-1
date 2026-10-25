
#include <stdio.h>

int main(void)
{
    int units;
    long bill;

    printf("Enter electricity units: ");

    if (scanf("%d", &units) != 1)
    {
        printf("Invalid input! Enter a number.\n");
        return 1;
    }

    if (units < 0)
    {
        printf("Units cannot be negative.\n");
        return 1;
    }

    bill = 5000L;

    if (units > 200)
        bill += (units - 200L) * 450L;

    if (units > 100)
        bill += (units > 200 ? 100L : units - 100L) * 225L;

    printf("Units = %d\n", units);
    printf("Bill = Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}

