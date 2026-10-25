#include <stdio.h>

int main(void)
{
    FILE *file;
    int units;
    long fixed_charge, rate2, rate3, bill;

    file = fopen("tariff.txt", "r");

    if (file == NULL)
    {
        printf("Error: tariff.txt not found.\n");
        return 1;
    }

    if (fscanf(file, "%ld %ld %ld",
               &fixed_charge, &rate2, &rate3) != 3)
    {
        printf("Invalid tariff file.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Enter electricity units: ");

    if (scanf("%d", &units) != 1 || units < 0)
    {
        printf("Invalid units.\n");
        return 1;
    }

    bill = fixed_charge;

    if (units > 200)
        bill += (long)(units - 200) * rate3;

    if (units > 100)
        bill += (long)(units > 200 ? 100 : units - 100)
                * rate2;

    printf("Units consumed: %d\n", units);
    printf("Total bill: Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
