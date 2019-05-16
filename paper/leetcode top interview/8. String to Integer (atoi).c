

int myAtoi(char * str)
{
	int s=0, i, sum=0;
	char *p=NULL, *q=NULL, *tmp;
	char max[11]={'2', '1', '4', '7', '4', '8', '3', '6', '4', '7'}, min[11]={'2', '1', '4', '7', '4', '8', '3', '6', '4', '8'};

	tmp=(char*)malloc(sizeof(char)*(strlen(str)+1));
	memset(tmp, 0, sizeof(char)*(strlen(str)+1));

	for(i=0; i<strlen(str); ++i)
	{
		if(str[i] == ' ' && p == NULL){
			continue;
		}
		else
		{
			if(p == NULL)
			{
				if(str[i] == '+' || str[i] == '-' || str[i] >= '0' && str[i] <= '9'){
					p=str+i;
				}
				else{
					return 0;
				}
			}
			else
			{
				if(!(str[i] >= '0' && str[i] <= '9'))
				{
					q=str+i;
					break;
				}
			}
		}
	}
	if(p == NULL){
		return 0;
	}
	else
	{
		if(p[0] == '-' || p[0] == '+')
		{
			if(p[0] == '-'){
				s=1;
			}
			p++;
		}
		if(i == strlen(str)){
			strcpy(tmp, p);
		}
		else
		{
			if(p <= q){
				memcpy(tmp, p, q-p);
			}
			else{
				return 0;
			}
		}
	}
	if(strlen(tmp) == 0){
		return 0;
	}
	q=tmp;
	for(i=0; i<strlen(tmp)-1; ++i)
	{
		if(tmp[i] == '0'){
			continue;
		}
		else{
			break;
		}
	}
	tmp += i;
	if(s == 0)
	{
		if(strlen(tmp) > strlen(max) || strlen(tmp) == strlen(max) && strcmp(tmp, max) >= 0){
			return (int)pow(2, 31);
		}
	}
	else
	{
		if(strlen(tmp) > strlen(min) || strlen(tmp) == strlen(min) && strcmp(tmp, min) >= 0){
			return (int)pow(-2, 31);
		}
	}
	for(i=strlen(tmp)-1; i>=0; --i){
		sum += (tmp[i]-'0')*(int)pow(10, strlen(tmp)-1-i);
	}
	if(s == 1){
		return -sum;
	}
	free(q);

	return sum;
}

