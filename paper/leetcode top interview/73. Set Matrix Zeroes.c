

void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    char *row, *col;
    int i, j;
    
    row=(char*)malloc(sizeof(char)*matrixSize);
    col=(char*)malloc(sizeof(char)*(*matrixColSize));
    memset(row, 0, sizeof(char)*matrixSize);
    memset(col, 0, sizeof(char)*(*matrixColSize));
    
    for(i=0; i<matrixSize; ++i)
    {
        for(j=0; j<*matrixColSize; ++j)
        {
            if(matrix[i][j] == 0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    
    for(i=0; i<matrixSize; ++i)
    {
        if(row[i] == 1)
        {
            for(j=0; j<*matrixColSize; ++j){
                matrix[i][j]=0;
            }
        }
    }
    
    for(j=0; j<*matrixColSize; ++j)
    {
        if(col[j] == 1)
        {
            for(i=0; i<matrixSize; ++i){
                matrix[i][j]=0;
            }
        }
    }
    
    free(row);
    free(col);
}

