

void updateSudoku(char* board, int row, int col)
{
	int i, j, index;

	index = board[(row * 9 + col) * 10] - '0';
	for(i = 0; i < 9; ++i)
	{
		board[row * 9 * 10 + i * 10 + index] = 1;
		board[col * 10 + i * 9 * 10 + index] = 1;
	}
	for(i = 0; i < 3; ++i)
	{
		for(j = 0; j < 3; ++j){
			board[(row / 3 * 3 + i) * 9 * 10 + (col / 3 * 3 + j) * 10 + index] = 1;
		}
	}
}

void searchSudoku(char* board, int n, int *flag)
{
	char temp[9 * 9 * 10];
	int i;

	if(n == 9 * 9 -1)
	{
		if(board[n * 10] == '.')
		{
			for(i = 1; i <= 9; ++i)
			{
				if(board[n * 10 + i] == 0){
					board[n * 10] = '0' + i;
				}
			}
		}
		*flag = 1;
		return;
	}
	else
	{
		if(board[n * 10] != '.'){
			searchSudoku(board, n + 1, flag);
		}
		else
		{
			for(i = 1; i <= 9; ++i)
			{
				if(board[n * 10 + i] == 0)
				{
					board[n * 10] = '0' + i;
					memcpy(temp, board, sizeof(char) * 9 * 9 * 10);
					updateSudoku(board, n / 9, n % 9);
					searchSudoku(board, n + 1, flag);
					if(*flag == 1){
						return;
					}
					memcpy(board, temp, sizeof(char) * 9 * 9 * 10);
					board[n * 10] = '.';
				}
			}
		}
	}
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
	char temp[9 * 9 * 10];
	int i, flag = 0;

	memset(temp, 0, sizeof(char) * 9 * 9 * 10);
	for(i = 0; i < 9 * 9; ++i)
	{
		temp[i * 10] = board[i / 9][i % 9];
		if(temp[i * 10] != '.'){
			updateSudoku(temp, i / 9, i % 9);
		}
	}

	searchSudoku(temp, 0, &flag);
	for(i = 0; i < 9 * 9; ++i){
		board[i / 9][i % 9] = temp[i * 10];
	}
}
