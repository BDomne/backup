

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **array=NULL, i, j, n=1;
    
    *returnSize=(int)pow(2, numsSize);
    array=(int**)malloc(sizeof(int*)*(*returnSize));
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
    
    for(i=0; i<*returnSize; ++i)
    {
        array[i]=NULL;
        (*returnColumnSizes)[i]=0;
    }
    
    for(i=0; i<numsSize; ++i)
    {
        for(j=0; j<n; ++j)
        {
            (*returnColumnSizes)[n+j]=(*returnColumnSizes)[j]+1;
            array[n+j]=(int*)malloc(sizeof(int)*(*returnColumnSizes)[n+j]);
            if(array[j] != NULL){
                memcpy(array[n+j], array[j], sizeof(int)*(*returnColumnSizes)[j]);
            }
            array[n+j][(*returnColumnSizes)[j]]=nums[i];
        }
        n=n+j;
    }
    
    return array;
}

