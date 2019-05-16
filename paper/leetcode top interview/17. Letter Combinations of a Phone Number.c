

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void combine(char *digits, int index, char **result, char letter[10][5], char *tmp, int *num)
{
	unsigned int i;

	if(index == strlen(digits))
	{
		strcpy(result[*num], tmp);
		(*num)++;
	}
	else
	{
		for(i=0; i<strlen(letter[digits[index]-'0']); ++i)
		{
			tmp[index]=letter[digits[index]-'0'][i];
			combine(digits, index+1, result, letter, tmp, num);
		}
	}
}

char ** letterCombinations(char * digits, int* returnSize)
{
	char **result=NULL, *tmp;
	char letter[10][5]={{' '}, {' '}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
	{'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
	{'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
	int i, n, m=1, num=0;

	n=strlen(digits);
	if(n == 0)
	{
		*returnSize=0;
		return result;
	}
	tmp=(char*)malloc(sizeof(char)*(n+1));
	memset(tmp, 0, sizeof(char)*(n+1));
	for(i=0; i<n; ++i){
		m *= strlen(letter[digits[i]-'0']);
	}
	*returnSize=m;
	result=(char**)malloc(sizeof(char*)*m);
	for(i=0; i<m; ++i)
	{
		result[i]=(char*)malloc(sizeof(char)*(n+1));
		memset(result[i], 0, sizeof(char)*(n+1));
	}
	combine(digits, 0, result, letter, tmp, &num);

	return result;
}
