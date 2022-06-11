bool isSafe(int row, int col, int matrix[9][9], int c)
{

    for (int i = 0; i < 9; i++)
    {
        if (matrix[i][col] == c)
        {
            return false;
        }
        if (matrix[row][i] == c)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (matrix[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isSafe(i, j, matrix, k))
                    {
                        matrix[i][j] = k;
                        if (solve(matrix) == true)
                            return true;
                        else
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9])
{
    if (solve(matrix) == true)
    {
        return true;
    }
    return false;
}
