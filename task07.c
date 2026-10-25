
#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 2;
    long amount = 12345L;
    float price = 10.0f;

    printf("Integer division: %d / %d = %d\n", a, b, a / b);

    printf("Float division: %.2f / %d = %.2f\n",
           (float)a, b, (float)a / b);

    printf("Money in rupees: Rs %ld\n", amount / 100);

    printf("Money in paise: %ld\n", amount % 100);

    printf("Float price: %.2f\n", price);

    printf("Correct bill format: Rs %ld.%02ld\n",
           amount / 100, amount % 100);

    return 0;
}

