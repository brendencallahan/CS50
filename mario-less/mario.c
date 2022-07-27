#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Define variables

    int h;
    int r;
    int c;
    int s;

    // Get input

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);


    // Nested for loop

    for (c = 0; c < h; c++)
    {
        for (s = h - c - 1; s > 0; s--)
        {
            printf(" ");
        }
        for (r = -1; r < c; r++)
        {
            printf("#");
        }
        printf("\n");
    }



}