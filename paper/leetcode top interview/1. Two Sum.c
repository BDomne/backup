/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int *result, i, j, label=0;
    
    result=(int*)malloc(sizeof(int)*2);
    for(i=0; i<numsSize-1; ++i)
    {
        for(j=i+1; j<numsSize; ++j)
        {
            if(nums[i]+nums[j] == target)
            {
                label=1;
                break;
            }
        }
        if(label == 1){
            break;
        }
    }
    result[0]=i;
    result[1]=j;
    
    return result;
}
