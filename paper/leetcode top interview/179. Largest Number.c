

int cmp(const void *a, const void *b)
{
	char *m=(char*)a, *n=(char*)b, *p=NULL, *q=NULL;
	int len1, len2, result;

	len1=strlen(m);
	len2=strlen(n);
	p=(char*)malloc(sizeof(char)*(len1+len2+1));
	q=(char*)malloc(sizeof(char)*(len1+len2+1));
	memcpy(p, m, len1);
	memcpy(p+len1, n, len2);
	p[len1+len2]='\0';
	memcpy(q, n, len2);
	memcpy(q+len2, m, len1);
	p[len1+len2]='\0';
	result=strcmp(q, p);
	free(p);
	free(q);

	return result;
}

char * largestNumber(int* nums, int numsSize)
{
	char *array=NULL, *result=NULL, tmp[11];
	int i, j, n=0, m;

	if(numsSize == 0){
		return "";
	}
	array=(char*)malloc(sizeof(char)*11*numsSize);
	memset(array, 0, sizeof(char)*11*numsSize);
	for(i=0; i<numsSize; ++i)
	{
		j=9;
		memset(tmp, '0', sizeof(char)*10);
		tmp[10]='\0';
		while(nums[i]/10)
		{
			tmp[j]=nums[i]%10+'0';
			nums[i]=nums[i]/10;
			j--;
		}
		tmp[j]=nums[i]%10+'0';
		j=0;
		while(tmp[j] == '0' && j != strlen(tmp)-1){
			j++;
		}
		m=strlen(tmp+j);
		strcpy(array+i*11, tmp+j);
		n += m;
	}
	result=(char*)malloc(sizeof(char)*(n+1));
	memset(result, 0, sizeof(char)*(n+1));

	qsort(array, numsSize, sizeof(char)*11, cmp);
	for(i=0; i<numsSize; ++i){
		strcat(result, array+i*11);
	}
	free(array);
	j=0;
	while(result[j] == '0' && j != strlen(result)-1){
		j++;
	}

	return result+j;
}

