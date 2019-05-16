

void search(char **board, int boardrow, int boardcol, char *word, char *bitmap, int *result, int index, int row, int col)
{
    int label=0;
    
    if(strlen(word) == index+1){
        label=1;
    }
    
    if(*result == 0 && row-1 >= 0 && bitmap[(row-1)*boardcol+col] == 0)
    {
        if(board[row-1][col] == word[index])
        {
            if(label == 1)
            {
                *result=1;
                return;
            }
            else
            {
                bitmap[(row-1)*boardcol+col]=1;
                search(board, boardrow, boardcol, word, bitmap, result, index+1, row-1, col);
                bitmap[(row-1)*boardcol+col]=0;
            }
        }
    }
    
    if(*result == 0 && row+1 < boardrow && bitmap[(row+1)*boardcol+col] == 0)
    {
        if(board[row+1][col] == word[index])
        {
            if(label == 1)
            {
                *result=1;
                return;
            }
            else
            {
                bitmap[(row+1)*boardcol+col]=1;
                search(board, boardrow, boardcol, word, bitmap, result, index+1, row+1, col);
                bitmap[(row+1)*boardcol+col]=0;
            }
        }
    }
    
    if(*result == 0 && col-1 >= 0 && bitmap[row*boardcol+col-1] == 0)
    {
        if(board[row][col-1] == word[index])
        {
            if(label == 1)
            {
                *result=1;
                return;
            }
            else
            {
                bitmap[row*boardcol+col-1]=1;
                search(board, boardrow, boardcol, word, bitmap, result, index+1, row, col-1);
                bitmap[row*boardcol+col-1]=0;
            }
        }
    }
    
    if(*result == 0 && col+1 < boardcol && bitmap[row*boardcol+col+1] == 0)
    {
        if(board[row][col+1] == word[index])
        {
            if(label == 1)
            {
                *result=1;
                return;
            }
            else
            {
                bitmap[row*boardcol+col+1]=1;
                search(board, boardrow, boardcol, word, bitmap, result, index+1, row, col+1);
                bitmap[row*boardcol+col+1]=0;
            }
        }
    }
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
    char *bitmap;
    int i, j, k, result=0;
    
    if(strlen(word) == 0){
        return 1;
    }
    bitmap=(char*)malloc(sizeof(char)*boardSize*(*boardColSize));
    for(i=0; i<boardSize; ++i)
    {
        for(j=0; j<*boardColSize; ++j)
        {
            if(board[i][j] == word[0])
            {
                memset(bitmap, 0, sizeof(char)*boardSize*(*boardColSize));
                bitmap[i*(*boardColSize)+j]=1;
                if(strlen(word) == 1){
                    result=1;
                }
                else{
                    search(board, boardSize, *boardColSize, word, bitmap, &result, 1, i, j);
                }
            }
            if(result == 1){
                break;
            }
            if(result == 1){
                break;
            }
        }
    }
    
    return result;
}

