

#define MAXLEN 201

void searchInterleave(char *s1, int start1, int end1, char *s2, int start2, int end2, char *s3, int start3, int end3, int *flag)
{
	if(end3 - start3 > 1)
	{
		if(end1 - start1 > 1 && s3[start3] == s1[start1] && s3[end3 - 1] == s1[end1 - 1])
		{
			searchInterleave(s1, start1 + 1, end1 - 1, s2, start2, end2, s3, start3 + 1, end3 - 1, flag);
			if(*flag == 1){
				return;
			}
		}
		if(end1 - start1 >= 1 && end2 - start2 >= 1 && s3[start3] == s1[start1] && s3[end3 - 1] == s2[end2 - 1])
		{
			searchInterleave(s1, start1 + 1, end1, s2, start2, end2 - 1, s3, start3 + 1, end3 - 1, flag);
			if(*flag == 1){
				return;
			}
		}
		if(end1 - start1 >= 1 && end2 - start2 >= 1 && s3[start3] == s2[start2] && s3[end3 - 1] == s1[end1 - 1])
		{
			searchInterleave(s1, start1, end1 - 1, s2, start2 + 1, end2, s3, start3 + 1, end3 - 1, flag);
			if(*flag == 1){
				return;
			}
		}
		if(end2 - start2 > 1 && s3[start3] == s2[start2] && s3[end3 - 1] == s2[end2 - 1])
		{
			searchInterleave(s1, start1, end1, s2, start2 + 1, end2 - 1, s3, start3 + 1, end3 - 1, flag);
			if(*flag == 1){
				return;
			}
		}
	}
	else
	{
		if(end3 - start3 == 1 && end1 - start1 == 1 && s3[start3] == s1[start1] ||
			end3 - start3 == 1 && end2 - start2 == 1 && s3[start3] == s2[start2] ||
			end3 == start3){
				*flag = 1;
				return;
		}
	}
}

bool isInterleave(char *s1, char *s2, char *s3)
{
	char temp[MAXLEN] = {0};
	int letters[26] = {0}, flag = 0, i;

	if(strlen(s1) + strlen(s2) != strlen(s3)){
		return false;
	}
	strcat(temp, s1);
	strcat(temp, s2);
	if(strcmp(temp, s3) == 0){
		return true;
	}
	for(i = 0; i < strlen(s1); ++i){
		++letters[s1[i] - 'a'];
	}
	for(i = 0; i < strlen(s2); ++i){
		++letters[s2[i] - 'a'];
	}
	for(i = 0; i < strlen(s3); ++i){
		--letters[s3[i] - 'a'];
	}
	for(i = 0; i < 26; ++i)
	{
		if(letters[i] != 0){
			return false;
		}
	}

	searchInterleave(s1, 0, strlen(s1), s2, 0, strlen(s2), s3, 0, strlen(s3), &flag);
	if(flag == 1){
		return true;
	}
	return false;
}
