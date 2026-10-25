#include <stdio.h>

int main(void)
{
    FILE *file;
    int watt_hours, hour;
    long long fixed_charge, rate;
    long long numerator, charge;

    file = fopen("tariff12.txt", "r");

    if (file == NULL)
    {
        printf("Error: tariff12.txt not found.\n");
        return 1;
    }

    if (fscanf(file, "%lld %lld",
               &fixed_charge, &rate) != 2)
    {
        printf("Invalid tariff file.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Enter energy used in Wh: ");
    if (scanf("%d", &watt_hours) != 1 || watt_hours < 0)
    {
        printf("Invalid energy reading.\n");
        return 1;
    }

    printf("Enter hour (0-23): ");
    if (scanf("%d", &hour) != 1 || hour < 0 || hour > 23)
    {
        printf("Invalid hour.\n");
        return 1;
    }

    numerator = (long long)watt_hours * rate;

    if (hour >= 18 && hour < 22)
    {
        numerator *= 120;
        charge = (numerator + 50000) / 100000;
        printf("Peak hours: 20%% higher rate\n");
    }
    else
    {
        charge = (numerator + 500) / 1000;
        printf("Off-peak hours\n");
    }

    printf("Energy used: %d Wh\n", watt_hours);
    printf("Energy charge: %lld paise\n", charge);
    printf("Energy charge: Rs %lld.%02lld\n",
           charge / 100, charge % 100);

    return 0;
}
