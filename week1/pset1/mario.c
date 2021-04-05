#include <stdio.h>
#include <cs50.h>

int retrieve_height(void);
void display_steps(int n);

int main(void)
{
    int height = retrieve_height();
    display_steps(height);
}

int retrieve_height(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num <= 0 || num > 8);

    return num;
}

void display_steps(int n)
{
    // Iterates up to the number of times that user entered
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
