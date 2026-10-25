
#include <stdio.h>

#define FIXED_CHARGE 5000L
#define RATE2 225L
#define RATE3 450L

unsigned int consumption(unsigned short previous,
                         unsigned short current)
{
    return (unsigned short)(current - previous);
}

long compute_bill(unsigned int units)
{
    long bill = FIXED_CHARGE;

    if (units > 200)
        bill += (units - 200) * RATE3;

    if (units > 100)
        bill += (units > 200 ? 100 : units - 100) * RATE2;

    return bill;
}

int main(void)
{
    int previous, current;
    unsigned int units;
    long bill;

    printf("Enter previous meter reading (0-65535): ");
    if (scanf("%d", &previous) != 1 ||
        previous < 0 || previous > 65535)
    {
        printf("Invalid previous reading!\n");
        return 1;
    }

    printf("Enter current meter reading (0-65535): ");
    if (scanf("%d", &current) != 1 ||
        current < 0 || current > 65535)
    {
        printf("Invalid current reading!\n");
        return 1;
    }

    if (current < previous && previous < 65000)
    {
        printf("Invalid reading: no valid rollover detected.\n");
        return 1;
    }

    units = consumption((unsigned short)previous,
                        (unsigned short)current);

    bill = compute_bill(units);

    printf("Units consumed = %u\n", units);
    printf("Total bill = Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}

