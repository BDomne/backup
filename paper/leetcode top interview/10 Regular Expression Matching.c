

void handleA(char *s, char *p, int n, int m, int *result, char a, char c, int *label)
{
	int i;

	if(n<strlen(s) && m<strlen(p))
	{
		if(*label == 0 && s[n] == p[m]){
			handleA(s, p, n+1, m+1, result, p[m], ' ', label);
		}
		if(*label == 0 && p[m] == '.'){
			handleA(s, p, n+1, m+1, result, p[m], ' ', label);
		}
		if(*label == 0 && m < strlen(p)-1 && p[m+1] == '*'){
			handleA(s, p, n, m+2, result, ' ', ' ', label);
		}
		if(*label == 0 && p[m] == '*'){
			handleA(s, p, n, m+1, result, ' ', ' ', label);
		}
		if(*label == 0 && (p[m] == '*' || c == '*'))
		{
			if(s[n] == a || '.' == a){
				handleA(s, p, n+1, m, result, a, '*', label);
			}
		}
	}
	else
	{
		for(i=n; i<strlen(s); ++i)
		{
			if(!(c == '*' && s[i] == a))
			{
				*result=0;
				break;
			}
		}
		for(i=m; i<strlen(p); ++i)
		{
			if(p[i] == '*'){
				continue;
			}
			if(!(i < strlen(p)-1 && p[i+1] == '*'))
			{
				*result=0;
				break;
			}
			else{
				++i;
			}
		}
		if(*result == 1){
			*label=1;
		}
		*result=1;
	}
}

bool isMatch(char * s, char * p)
{
	int i, result=1, label=0;

	if(strchr(p, '*') == NULL && strchr(p, '.') == NULL){
		if(strcmp(s, p) != 0){
			result=0;
		}
	}
	else
	{
		if(strchr(p, '*') == NULL && strchr(p, '.') != NULL)
		{
			if(strlen(s) != strlen(p)){
				result=0;
			}
			else
			{
				for(i=0; i<strlen(s); ++i)
				{
					if(s[i] != p[i] && p[i] != '.')
					{
						result=0;
						break;
					}
				}
			}
		}
		else
		{
			handleA(s, p, 0, 0, &result, ' ', ' ', &label);
			if(label == 0){
				result=0;
			}
		}
	}

	return result;
}

