#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int height = -1;
   while(height < 0 || height > 23)
   {
       printf("Height: ");
       height = GetInt();
   }
   
   int spaces = height - 1;
   int cols = 2;
   for(int i = 0; i < height; i++)
   {
       for(int space = 0; space < spaces; space++)
       {
           printf(" ");
       }
       
       for(int col = 0; col < cols; col++)
       {
           printf("#");
       }
       
       spaces--;
       cols++;
       printf("\n");
   }
}