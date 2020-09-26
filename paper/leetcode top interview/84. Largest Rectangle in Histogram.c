

void searchRectangleArea(int* heights, int start, int end, int* result)
{
	int max, min, index, i;

	for(max = min = heights[start], index = i = start; i < end; ++i)
	{
		if(max < heights[i]){
			max = heights[i];
		}
		if(min > heights[i])
		{
			min = heights[i];
			index = i;
		}
	}
	if(*result < min * (end - start)){
		*result = min * (end - start);
	}

	if(max > min)
	{
		if(index - start > 0){
			searchRectangleArea(heights, start, index, result);
		}
		if(end - index > 1){
			searchRectangleArea(heights, index + 1, end, result);
		}
	}
}

int largestRectangleArea(int* heights, int heightsSize)
{
	int result = 0;

	if(heightsSize > 0){
		searchRectangleArea(heights, 0, heightsSize, &result);
	}

	return result;
}
