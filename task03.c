#include <stdio.h>

#define FIXED_CHARGE 5000
#define SLAB1_LIMIT 100
#define SLAB2_LIMIT 200
#define RATE1 0
#define RATE2 225
#define RATE3 450

int main(void)
{
    printf("Fixed charge = Rs %d.%02d\n",
           FIXED_CHARGE / 100, FIXED_CHARGE % 100);

    printf("First slab limit = %d units\n", SLAB1_LIMIT);
    printf("Second slab limit = %d units\n", SLAB2_LIMIT);

    printf("Rate for first slab = %d paise/unit\n", RATE1);
    printf("Rate for second slab = %d paise/unit\n", RATE2);
    printf("Rate above 200 units = %d paise/unit\n", RATE3);

    return 0;
}
