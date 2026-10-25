
#include <stdio.h>

int main(void)
{
    int units = 150;
    long bill = 16250L;

    printf("Electricity units = %d\n", units);
    printf("Bill = Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}

