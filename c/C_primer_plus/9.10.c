#include <stdio.h>

void to_base_n(unsigned long number, int base);

int main(void)
{
    int base;
    unsigned long number;

    printf("Please enter a number (q to quit): ");
    while (scanf("%ld", &number) == 1)
    {
        if (number <= 0)
        {
            printf("Illegal data! Please enter again: ");
            continue;
        }
        printf("Please enter a base system number (2 - 10): ");
        while (scanf("%d", &base) != 1 || (base < 2 || base > 10))
        {
            while (getchar() != '\n')
                continue;
            printf("Please enteragain (2 - 10): ");
        }
        printf("%d in %d base system is: ", number, base);
        to_base_n(number, base);
        printf("\nYou can enter a number again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(unsigned long number, int base){
    if(number != 0){
        to_base_n(number / base, base);
        putchar('0' + number % base);
    }
}