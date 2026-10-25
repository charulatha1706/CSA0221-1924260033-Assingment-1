#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define RUPEES_TO_PAISE(x) ((x) * 100)

int main(void)
{
    int number = 5;
    int rupees = 50;

    printf("Square of %d = %d\n", number, SQUARE(number));
    printf("Square of 5 + 1 = %d\n", SQUARE(5 + 1));
    printf("Rs %d in paise = %d\n",
           rupees, RUPEES_TO_PAISE(rupees));

    return 0;
}
