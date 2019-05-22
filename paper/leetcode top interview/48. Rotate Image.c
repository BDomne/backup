

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int i, j, k, tmp;
    
    for(i=matrixSize, k=0; i>1; i=i-2, ++k)
    {
        for(j=0; j<i-1; ++j)
        {
            tmp=matrix[k][k+j];
            matrix[k][k+j]=matrix[matrixSize-1-k-j][k];
            matrix[matrixSize-1-k-j][k]=matrix[matrixSize-1-k][matrixSize-1-k-j];
            matrix[matrixSize-1-k][matrixSize-1-k-j]=matrix[k+j][matrixSize-1-k];
            matrix[k+j][matrixSize-1-k]=tmp;
        }
    }
}

