
char * longestCommonPrefix(char ** strs, int strsSize)
{
	char *str, c;
	int i, j, n, m, label=0;

	if(strsSize == 0){
		return "";
	}
	else
	{
		n=strlen(strs[0]);
		for(i=0; i<strsSize; ++i)
		{
			m=strlen(strs[i]);
			if(m == 0){
				return "";
			}
			if(m < n){
				n=m;
			}
		}
		for(i=0; i<m; ++i)
		{
			c=strs[0][i];
			for(j=1; j<strsSize; ++j)
			{
				if(strs[j][i] != c)
				{
					label=1;
					break;
				}
			}
			if(label == 1){
				break;
			}
		}
		str=(char*)malloc(sizeof(char)*(i+1));
		memset(str, 0, i+1);
		memcpy(str, strs[0], i);
	}

	return str;
}

