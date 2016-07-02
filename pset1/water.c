#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int minutes = 0;
    
    printf("minutes: ");
    minutes = GetInt();
    printf("bottles: %d\n", (minutes*192)/16);
    
    return 0;
}