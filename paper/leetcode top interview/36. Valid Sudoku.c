

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    char label[9];
    int i, j, m, n;
    
    for(i=0; i<boardSize; ++i)
    {
        memset(label, 0, sizeof(char)*9);
        for(j=0; j<*boardColSize; ++j)
        {
            if(board[i][j] != '.'){
                label[board[i][j]-'1']++;
            }
        }
        for(j=0; j<9; ++j)
        {
            if(label[j] > 1){
                return 0;
            }
        }
    }
    
    for(i=0; i<*boardColSize; ++i)
    {
        memset(label, 0, sizeof(char)*9);
        for(j=0; j<boardSize; ++j)
        {
            if(board[j][i] != '.'){
                label[board[j][i]-'1']++;
            }
        }
        for(j=0; j<9; ++j)
        {
            if(label[j] > 1){
                return 0;
            }
        }
    }
    
    for(i=0; i<boardSize/3; ++i)
    {
        for(j=0; j<*boardColSize/3; ++j)
        {
            memset(label, 0, sizeof(char)*9);
            for(m=0; m<3; ++m)
            {
                for(n=0; n<3; ++n)
                {
                    if(board[i*3+m][j*3+n] != '.'){
                        label[board[i*3+m][j*3+n]-'1']++;
                    }
                }
            }
            for(m=0; m<9; ++m)
            {
                if(label[m] > 1){
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

