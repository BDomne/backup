

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void traversal(int **array, int *cnt, int *nums, char *label, int *tmp, int numsSize, int index)
{
    int i;
    
    if(index == numsSize)
    {
        memcpy(array[*cnt], tmp, sizeof(int)*numsSize);
        (*cnt)++;
    }
    else
    {
        for(i=0; i<numsSize; ++i)
        {
            if(label[i] == 0)
            {
                tmp[index]=nums[i];
                label[i]=1;
                traversal(array, cnt, nums, label, tmp, numsSize, index+1);
                label[i]=0;
            }
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **array, cnt=0, i, n=1, *tmp;
    char *label;
    
    for(i=numsSize; i>0; --i){
        n *= i;
    }
    *returnSize=n;
    array=(int**)malloc(sizeof(int*)*n);
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    for(i=0; i<n; ++i)
    {
        array[i]=(int*)malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[i]=numsSize;
    }
    tmp=(int*)malloc(sizeof(int)*numsSize);
    label=(char*)malloc(sizeof(char)*numsSize);
    memset(label, 0, sizeof(char)*numsSize);
    traversal(array, &cnt, nums, label, tmp, numsSize, 0);
    free(label);
    free(tmp);
    
    return array;
}

