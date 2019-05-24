

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    return **((int**)a) - **((int**)b);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    char *label=NULL;
    int **result=NULL, i, n=0;
    
    if(intervalsSize == 0)
    {
        *returnSize=0;
        return result;
    }
    label=(char*)malloc(sizeof(char)*intervalsSize);
    memset(label, 0, sizeof(char)*intervalsSize);
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    
    for(i=1; i<intervalsSize; ++i)
    {
        if(intervals[i][0] <= intervals[i-1][1])
        {
            intervals[i][0]=intervals[i-1][0];
            if(intervals[i][1] < intervals[i-1][1]){
                intervals[i][1]=intervals[i-1][1];
            }
        }
        else
        {
            label[i-1]=1;
            n++;
        }
    }
    label[i-1]=1;
    n++;
    
    *returnSize=n;
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    result=(int**)malloc(sizeof(int*)*n);
    for(i=0, n=0; i<intervalsSize; ++i)
    {
        if(label[i] == 1)
        {
            result[n]=(int*)malloc(sizeof(int)*2);
            result[n][0]=intervals[i][0];
            result[n][1]=intervals[i][1];
            (*returnColumnSizes)[n]=2;
            n++;
        }
    }
    free(label);
    
    return result;
}

