#include <stdio.h>

int main(void)
{
    FILE *file;
    long long fixed_charge, rate, watt_hours;
    long long factor, charge, numerator;
    int peak_start, peak_end, increase, hour;

    file = fopen("tariff.txt", "r");

    if (file == NULL)
    {
        printf("Error opening tariff file!\n");
        return 1;
    }

    if (fscanf(file, "%lld %lld %d %d %d",
               &fixed_charge, &rate,
               &peak_start, &peak_end,
               &increase) != 5)
    {
        printf("Invalid tariff settings!\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    if (fixed_charge < 0 || rate < 0 ||
        peak_start < 0 || peak_start > 23 ||
        peak_end < 1 || peak_end > 24 ||
        increase < 0)
    {
        printf("Invalid tariff values!\n");
        return 1;
    }

    printf("Enter energy consumed in Wh: ");
    if (scanf("%lld", &watt_hours) != 1 ||
        watt_hours < 0 || watt_hours > 1000000000LL)
    {
        printf("Invalid energy reading!\n");
        return 1;
    }

    printf("Enter hour (0 to 23): ");
    if (scanf("%d", &hour) != 1 ||
        hour < 0 || hour > 23)
    {
        printf("Invalid hour!\n");
        return 1;
    }

    factor = 100;

    if (hour >= peak_start && hour < peak_end)
        factor += increase;

    numerator = watt_hours * rate * factor;

    /* Convert Wh and paise/kWh into paise,
       rounding to the nearest paisa. */
    charge = (numerator + 50000) / 100000;

    printf("Energy charge = Rs %lld.%02lld\n",
           charge / 100, charge % 100);

    printf("Fixed charge = Rs %lld.%02lld\n",
           fixed_charge / 100, fixed_charge % 100);

    printf("Total for this billing example = Rs %lld.%02lld\n",
           (charge + fixed_charge) / 100,
           (charge + fixed_charge) % 100);

    return 0;
}

