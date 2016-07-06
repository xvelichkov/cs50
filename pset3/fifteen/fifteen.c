/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

#define UNDERSCORE 95

// board
int board[DIM_MAX][DIM_MAX];

//empty tile indexes
int empty_tile_i = 0;
int empty_tile_j = 0;

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int number = (d*d) - 1;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
           board[i][j] = number;
           number--;
        }
    }

    // set empty tile
    empty_tile_i = d-1;
    empty_tile_j = d-1;

    // make board winnable if number of tiles is odd
    if(((d*d-1) % 2) != 0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
}

void drawTile(int tile, bool space)
{
    int max_width = 2;
    if(space == true)
    {
        if(tile == 0)
        {
            printf("%*c ", max_width, UNDERSCORE);
        }
        else
        {
            printf("%*i ", max_width, tile);
        }
    }
    else
    {
        if(tile == 0)
        {
            printf("%*c\n", max_width, UNDERSCORE);
        }
        else
        {
            printf("%*i\n", max_width, tile);
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            int tile = board[i][j];
            // last tile on the row
            if(j == d - 1)
            {
                drawTile(tile, false);
            }
            // tile
            else
            {
                drawTile(tile, true);
            }
        }
    }
    printf("\n");
}


/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // check left tile
    if(empty_tile_j > 0 && board[empty_tile_i][empty_tile_j - 1] == tile)
    {
        // move right
        board[empty_tile_i][empty_tile_j] = tile;
        board[empty_tile_i][--empty_tile_j] = 0;
        return true;
    }
    // check right tile
    if(empty_tile_j < (d - 1) && board[empty_tile_i][empty_tile_j + 1] == tile)
    {
        //move left
        board[empty_tile_i][empty_tile_j] = tile;
        board[empty_tile_i][++empty_tile_j] = 0;
        return true;
    }
    // check above tile
    if(empty_tile_i > 0 && board[empty_tile_i-1][empty_tile_j] == tile)
    {
        // move down
        board[empty_tile_i][empty_tile_j] = tile;
        board[--empty_tile_i][empty_tile_j] = 0;
        return true;
    }
    // check down tile
    if(empty_tile_i < (d - 1) && board[empty_tile_i+1][empty_tile_j] == tile)
    {
        // move up
        board[empty_tile_i][empty_tile_j] = tile;
        board[++empty_tile_i][empty_tile_j] = 0;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int current = board[0][0];
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if(i == 0 && j == 0)
            {
                // skip first
                continue;
            }
            else if(i == (d - 1) && j == (d - 1))
            {
                // skip last
                continue;
            }
            else if(current+1 != board[i][j])
            {
                // not yet
                return false;
            }
            else
            {
                current = board[i][j];
            }
        }
    }
    return true;
}