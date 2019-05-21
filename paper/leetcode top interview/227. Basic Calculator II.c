

int calculate(char * s)
{
	int nums[3], index1=-1, index2=-1, i=0;
	char ops[2], *str, tmp[11], *p=s, *q;
	
	str=(char*)malloc(sizeof(char)*(strlen(s)+1));
	while(*p != '\0')
	{
		if(*p != ' '){
			str[i++]=*p;
		}
		p++;
	}
	str[i]='\0';

	p=str;
	q=p+1;
	while(*q != '\0'){
		if(*q == '+' || *q == '-' || *q == '*' || *q == '/'){
			break;
		}
		q++;
	}
	memcpy(tmp, p, q-p);
	tmp[q-p]='\0';
	index1++;
	nums[index1]=atoi(tmp);

	while(*q != '\0')
	{
		if(*q == '+' || *q == '-' || *q == '*' || *q == '/')
		{
			index2++;
			ops[index2]=*q;
		}
		p=q+1;
		q=p+1;
		while(*q != '\0'){
			if(*q == '+' || *q == '-' || *q == '*' || *q == '/'){
				break;
			}
			q++;
		}
		memcpy(tmp, p, q-p);
		tmp[q-p]='\0';
		index1++;
		nums[index1]=atoi(tmp);
		if(index2 == 0)
		{
			if(ops[index2] == '*')
			{
				nums[0]=nums[0]*nums[1];
				index2--;
				index1--;
			}
			else
			{
				if(ops[index2] == '/')
				{
					nums[0]=nums[0]/nums[1];
					index2--;
					index1--;
				}
			}
		}
		else
		{
			if(index2 == 1)
			{
				switch(ops[index2])
				{
				case '*':
					nums[1]=nums[1]*nums[2];
					index2--;
					index1--;
					break;
				case '/':
					nums[1]=nums[1]/nums[2];
					index2--;
					index1--;
					break;
				case '+':
				case '-':
					if(ops[index2-1] == '+'){
						nums[0]=nums[0]+nums[1];
					}
					else{
						nums[0]=nums[0]-nums[1];
					}
					nums[1]=nums[2];
					ops[index2-1]=ops[index2];
					index2--;
					index1--;
				}
			}
		}
	}
	if(index2 == 0)
	{
		switch(ops[0])
		{
		case '+':
			nums[0]=nums[0]+nums[1];
			break;
		case '-':
			nums[0]=nums[0]-nums[1];
			break;
		case '*':
			nums[0]=nums[0]*nums[1];
			break;
		case '/':
			nums[0]=nums[0]/nums[1];
			break;
		}
	}
	free(str);
	
	return nums[0];
}

