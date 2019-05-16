
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp1(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int cmp2(const void *a, const void *b)
{
	if(*((int*)a) != *((int*)b)){
		return *((int*)a) - *((int*)b);
	}
	if(*((int*)a+1) != *((int*)b+1)){
		return *((int*)a+1) - *((int*)b+1);
	}
	return *((int*)a+2) - *((int*)b+2);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int i, *a=NULL, **b=NULL, n=0;
	int start, end;

	*returnSize=0;
	if(numsSize < 3){
		return NULL;
	}
	for(i=0; i<numsSize; ++i){
		if(nums[i] != 0){
			break;
		}
	}
	if(i == numsSize)
	{
		*returnSize=1;
		b=(int**)malloc(sizeof(int*));
		b[0]=(int*)malloc(sizeof(int)*3);
		b[0][0]=b[0][1]=b[0][2]=0;
		*returnColumnSizes=(int*)malloc(sizeof(int));
		(*returnColumnSizes)[0]=3;
		return b;
	}

	a=(int*)malloc(sizeof(int)*(20000*3));
	b=(int**)malloc(sizeof(int*)*20000);
	for(i=0; i<20000; ++i){
		b[i]=(int*)malloc(sizeof(int)*3);
	}
	qsort(nums, numsSize, sizeof(int), cmp1);

	for(i=0; i<numsSize-2; ++i)
	{
		if(nums[i] > 0){
			break;
		}
		start=i+1;
		end=numsSize-1;
		while(start < end)
		{
			if(nums[i]+nums[start]+nums[end] == 0)
			{
				a[n*3]=nums[i];
				a[n*3+1]=nums[start];
				a[n*3+2]=nums[end];
				n++;
				start++;
				end--;
			}
			else
			{
				if(nums[i]+nums[start]+nums[end] < 0){
					start++;
				}
				else{
					end--;
				}
			}
		}
	}

	if(n == 0){
		return NULL;
	}
	qsort(a, n, 3*sizeof(int), cmp2);

	b[*returnSize][0]=a[0];
	b[*returnSize][1]=a[1];
	b[*returnSize][2]=a[2];
	for(i=1; i<n; ++i)
	{
		if(!(a[i*3] == a[(i-1)*3] && a[i*3+1] == a[(i-1)*3+1] && a[i*3+2] == a[(i-1)*3+2]))
		{
			(*returnSize)++;
			b[*returnSize][0]=a[i*3];
			b[*returnSize][1]=a[i*3+1];
			b[*returnSize][2]=a[i*3+2];
		}
	}
	(*returnSize)++;
	free(a);
	a=NULL;

	*returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
	for(i=0; i<*returnSize; ++i){
		(*returnColumnSizes)[i]=3;
	}

	return b;
}
