#include <stdio.h>
#include <math.h>

#include <cs50.h>

int main(void)
{
    float change = -1.0;
    while(change < 0.0)
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    }
    
    int cents = (int)((round(change * 100) / 100) * 100);
    
    int coins = 0;
    while(cents > 0)
    {
        if(cents >= 25)
        {
            cents -= 25;
        }
        else if(cents >= 10)
        {
            cents -= 10;
        }
        else if(cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
        
        coins++;
    }
    
    printf("%d\n", coins);
    
    return 0;
}