

bool isValid(char * s)
{
	char valid[3][3]={{'(', ')'}, {'{', '}'}, {'[', ']'}};
	char *p, tmp[1024*8], tmp1[1024*8];
	int i, label=0;

	strcpy(tmp, s);
	while(1)
	{
		for(i=0; i<3; ++i)
		{
			if((p=strstr(tmp, valid[i])) != NULL)
			{
				if(strlen(tmp) == 2)
				{
					i=3;
					label=1;
					break;
				}
				strcpy(tmp1, p+2);
				strcpy(p, tmp1);
				break;
			}
		}
		if(i == 3){
			break;
		}
	}
	if(strlen(tmp) == 0 || label == 1){
		return 1;
	}

	return 0;
}

