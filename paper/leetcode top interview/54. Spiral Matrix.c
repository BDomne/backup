

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
	int *array, n=0, i;
	int r0=0, r1=0, r2=matrixSize-1, r3=*matrixColSize-1;

	if(matrixSize == 0)
	{
		*returnSize=0;
		return NULL;
	}
	*returnSize=matrixSize*(*matrixColSize);
	array=(int*)malloc(sizeof(int)*(*returnSize));
	while(r2 >= r0 && r3 >= r1)
	{
		if(r1 == r3 && r0 == r2)
		{
			array[n]=matrix[r0][r1];
			n++;
		}
		else
		{
			if(r1 == r3)
			{
				for(i=r0; i<=r2; ++i)
				{
					array[n]=matrix[i][r1];
					n++;
				}
			}
			else
			{
				if(r0 == r2)
				{
					for(i=r1; i<=r3; ++i)
					{
						array[n]=matrix[r0][i];
						n++;
					}
				}
				else
				{
					for(i=r1; i<r3; ++i)
					{
						array[n]=matrix[r0][i];
						n++;
					}
					for(i=r0; i<r2; ++i)
					{
						array[n]=matrix[i][r3];
						n++;
					}
					for(i=r3; i>r1; --i)
					{
						array[n]=matrix[r2][i];
						n++;
					}
					for(i=r2; i>r0; --i)
					{
						array[n]=matrix[i][r1];
						n++;
					}
				}
			}
		}
		r0++;
		r1++;
		r2--;
		r3--;
	}

	return array;
}

