#include "../common.h"

// TODO add check for bounds of falling_piece
int process_state(SDL_Color dead_blocks[][10], struct Piece *falling_piece)
{
    int row_full = 1;

    int num_rows_cleared = 0;

    for (int row = 19; row >= 0; row--)
    {
        for (int col = 0; col < 10; col++)
        {
            if (dead_blocks[row][col].a != 255)
            {
                row_full = 0;
            }
        }

        if (row_full)
        {
            for (int cleared_col = 0; cleared_col < 10; cleared_col++)
            {
                (*(dead_blocks + row)[cleared_col]).a = 0;
                dead_blocks[row][cleared_col].a = 0;
            }
            for (int falling_row = row - 1; falling_row >= 0; falling_row--)
            {
                for (int falling_col = 0; falling_col < 10; falling_col++)
                {
                    dead_blocks[falling_row + 1][falling_col] = dead_blocks[falling_row][falling_col];
                }
            }
            num_rows_cleared++;
            row = 20;
        }
        row_full = 1;
    }

    if (num_rows_cleared == 4)
    {
        return 50;
    }
    else
    {
        return num_rows_cleared * 10;
    }
}