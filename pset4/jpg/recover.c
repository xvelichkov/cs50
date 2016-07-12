/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    FILE* memory = fopen("card.raw", "r");
    
    if (memory)
    {
        char buffer[512] = {0};
        char jpg_sign[3] = {0xff, 0xd8, 0xff};
        int count = 0;
        
        FILE* current_out = NULL;
        
        // read 512 bytes
        while(fread(buffer, 512, 1, memory))
        {
            // check if current block begins with jpg signiture
            if ((memcmp(buffer, jpg_sign, sizeof(jpg_sign)) == 0) && 
                    (((buffer[3] & 0x000000ff) >> 4) == 0x0e))
            {
                // if file is already opened close it
                if (current_out != NULL)
                {
                    fclose(current_out);    
                }
                
                // construct file name
                char filename[8] = {0};
                sprintf(filename, "%03d.jpg", count);
                
                current_out = fopen(filename, "w");
                count++;
            }

            // if we have jpg and file is opened write current block
            if (current_out)
            {
                fwrite(buffer, 512, 1, current_out);
            }
            
            // reset buffer
            memset(buffer, 0, sizeof(buffer));
        }
    }
    else
    {
        printf("Could not open card.raw\n");
    }
    return 0;
}
