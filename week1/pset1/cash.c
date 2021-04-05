#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Global Variables
int remaining_change;
int coins_used = 0;

// Prototypes
float retrieve_amount_owed(void);
int convert_to_cents(float change_owed);
int calculate_number_of_quarters(void);
int calculate_number_of_dimes(void);
int calculate_number_of_nickles(void);
int calculate_number_of_pennies(void);

// Begining of main program
int main(void)
{
    float amount_owed = retrieve_amount_owed();
    int cents = convert_to_cents(amount_owed);

    remaining_change = cents;

    int total_quarters = calculate_number_of_quarters();
    int total_dimes = calculate_number_of_dimes();
    int total_nickles = calculate_number_of_nickles();
    int total_pennies = calculate_number_of_pennies();

    printf("%i\n", coins_used);
}

// Functions
float retrieve_amount_owed(void)
{
    float num;
    do
    {
        num = get_float("Change owed: ");
    }
    while (num <= 0.00);

    return num;
}

int convert_to_cents(float change_owed)
{
    int amount_in_cents = round(change_owed * 100);

    return amount_in_cents;
}

int calculate_number_of_quarters(void)
{
    int quarters = 0;
    while (remaining_change >= 25)
    {
        quarters = remaining_change / 25;
        remaining_change -= quarters * 25;
        coins_used += quarters;
        break;
    }

    return quarters;
}

int calculate_number_of_dimes(void)
{
    int dimes = 0;
    while (remaining_change >= 10)
    {
        dimes = remaining_change / 10;
        remaining_change -= dimes * 10;
        coins_used += dimes;
        break;
    }

    return dimes;
}

int calculate_number_of_nickles(void)
{
    int nickles = 0;
    while (remaining_change >= 5)
    {
        nickles = remaining_change / 5;
        remaining_change -= nickles * 5;
        coins_used += nickles;
        break;
    }

    return nickles;
}

int calculate_number_of_pennies(void)
{
    int pennies = 0;
    while (remaining_change == 1)
    {
        pennies = remaining_change / 1;
        remaining_change -= pennies * 1;
        coins_used += pennies;
        break;
    }

    return pennies;
}