#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("Hello, what's your name?\n");

    printf("Hello, %s.\n", answer);
}