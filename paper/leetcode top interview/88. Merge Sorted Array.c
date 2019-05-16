

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int len=m+n, index1=m-1, index2=n-1, i;

	for(i=len-1; i>=0; --i)
	{
		if(index1 >= 0 && index2 >= 0)
		{
			if(nums1[index1] > nums2[index2])
			{
				nums1[i]=nums1[index1];
				index1--;
			}
			else
			{
				nums1[i]=nums2[index2];
				index2--;
			}
		}
		else
		{
			if(index1 >= 0)
			{
				nums1[i]=nums1[index1];
				index1--;
			}
			if(index2 >= 0)
			{
				nums1[i]=nums2[index2];
				index2--;
			}
		}
	}
}

