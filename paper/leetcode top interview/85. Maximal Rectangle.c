

void searchRectangle(int **heights, int col, int heightsSize, int *result)
{
    int i, *heightStack = NULL, *widthStack = NULL, index = 0, max = 0;

    heightStack = (int *)malloc(sizeof(int) * heightsSize);
    widthStack = (int *)malloc(sizeof(int) * heightsSize);
    for(i = 0; i < heightsSize; ++i)
    {
        if(i == 0 || heights[i][col] > heightStack[index - 1])
        {
            heightStack[index] = heights[i][col];
            widthStack[index] = 1;
            ++index;
        }
        else
        {
            if(heights[i][col] == heightStack[index - 1]){
                ++widthStack[index - 1];
            }
            else
            {
                while(1)
                {
                    if(max < heightStack[index - 1] * widthStack[index - 1]){
                        max = heightStack[index - 1] * widthStack[index - 1];
                    }
                    if(index > 1)
                    {
                        if(heightStack[index - 2] < heights[i][col])
                        {
                            heightStack[index - 1] = heights[i][col];
                            ++widthStack[index - 1];
                            break;
                        }
                        else
                        {
                            if(heightStack[index - 2] == heights[i][col])
                            {
                                widthStack[index - 2] += widthStack[index - 1] + 1;
                                --index;
                                break;
                            }
                            else
                            {
                                widthStack[index - 2] += widthStack[index - 1];
                                --index;
                            }
                        }
                    }
                    else
                    {
                        heightStack[index - 1] = heights[i][col];
                        ++widthStack[index - 1];
                        break;
                    }
                }
            }
        }
    }

    while(index > 0)
    {
        if(max < heightStack[index - 1] * widthStack[index - 1]){
            max = heightStack[index - 1] * widthStack[index - 1];
        }
        if(index > 1){
            widthStack[index - 2] += widthStack[index - 1];
        }
        --index;
    }
    if(*result < max){
        *result = max;
    }
    free(heightStack);
    free(widthStack);
}

int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize)
{
    int **heights, i, j, n, result = 0;

    if(matrixSize > 0)
    {
        heights = (int **)malloc(sizeof(int *) * matrixSize);
        for(i = 0; i < matrixSize; ++i){
            heights[i] = (int *)malloc(sizeof(int) * matrixColSize[0]);
        }
        for(i = 0; i < matrixSize; ++i)
        {
            n = 0;
            for(j = matrixColSize[0] - 1; j >= 0; --j)
            {
                if(matrix[i][j] == '0'){
                    n = 0;
                }
                else{
                    ++n;
                }
                heights[i][j] = n;
            }
        }

        for(j = 0; j < matrixColSize[0]; ++j){
            searchRectangle(heights, j, matrixSize, &result);
        }
        for(i = 0; i < matrixSize; ++i){
            free(heights[i]);
        }
        free(heights);
    }
    
    return result;
}
