

void jump(int index, int *num, int size, int *result)
{
    int i;
    
    if(*result == 1){
        return;
    }
    if(index+num[index] >= size-1){
        *result=1;
    }
    else
    {
        for(i=num[index]; i>0 ; --i)
        {
            jump(index+i, num, size, result);
        }
    }
}

bool canJump(int* nums, int numsSize) 
{
    int i, result=0;
    
    if(numsSize > 2 && nums[numsSize-2] == 0)
    {
        for(i=0; i<numsSize-2; ++i)
        {
            if(nums[i] == 0 || i+nums[i] > numsSize-2 || nums[i+nums[i]] > 1){
                break;
            }
        }
        if(i == numsSize-2){
            return result;
        }
    }
    
    jump(0, nums, numsSize, &result);
    
    return result;
}

