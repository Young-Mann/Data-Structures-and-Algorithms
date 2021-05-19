
void instructions()
/* Pre: None.
   Post: Instructions for using the lifegame program have been printed. */
{
	cout << "Welcome to Conway's game of Life." << endl;
	cout << "This game uses a grid of size "
		 << maxrow << " by " << maxcol << " in which" << endl;
	cout << "each cell can either be occupied by an organism or not." << endl;
	cout << "The occupied cells change from generation to generation" << endl;
	cout << "according to the number of neighboring cells which are alive."
		 << endl;
}

bool user_says_yes()
{
	int c;
	bool initial_response = true;
	do {
		if (initial_response)
			cout << "(y, n)?" << flush;
		else
			cout << "Respond with either 'y' or 'n':" << flush;
		
		do {c = cin.get();} while (c == '\n' || c == ' ' || c == '\t');
		initial_response = false;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	
	return (c == 'y' || c == 'Y');
}

void Life::initialize()
/* Pre: None
   Post: The Life object gets a configuration specified by the user*/
{
	int row, col;
	for (row = 0; row <= maxrow; row ++ )
		for (col = 0; col <= maxcol; col ++ )
			grid[row][col] = 0;
	cout << "List the coordinates for living cells." << endl;
	cout << "Terminate the list with the special pair, namely '-1 -1'." << endl;
	cin >> row >> col;
	while (row != -1 || col != -1)
	{
		if (row >= 1 && row <= maxrow)
			if (col >= 1 && col <= maxcol)
				grid[row][col] = 1;
			else
				cout << "Column" << col << "is out of range." << endl;
		else
			cout << "Row" << row << "is out of range." << endl;
		
		cin >> row >> col;
	}
}

int Life::neighbor_count(int row, int col)
/* Pre: The Life object contains a configuration, and the coordinates "row" and "col" define a cell inside its hedge.
   Post: The number of living neighbors of the specified cell is returnes. */
{
	int i, j;
	int count = 0;

	int row_low = row - 1, row_high = row + 1,
		col_low = col - 1, col_high = col + 1;
	if (row == 1)	row_low ++ ;
	if (row == maxrow)	row_high -- ;
	if (col == 1) col_low ++ ;
	if (col == maxcol)	col_high -- ;
	
	for (i = row_low; i <= row_high; i ++ )
	{
		for (j = col_low; j <= col_high; j ++ )
			count += grid[i][j];	// Increase the count if the neighbor is alive.
	}	
	count -= grid[row][col];	// The specified cell is not its own neighbor.
	
	return count;
}


void Life::update()
/* Pre: The Life object contains a configuration.
   Pose: The Life object contains the next generation of configuration. */
{
	int row, col;
	int new_grid[maxrow + 2][maxcol + 2];
	for (row = 1; row <= maxrow; row ++ )
		for (col = 1; col <= maxcol; col ++ )
			switch (neighbor_count(row, col)) {
				case 2:
					new_grid[row][col] = grid[row][col];
					break;
				case 3:
					new_grid[row][col] = 1;
					break;
				default:
					new_grid[row][col] = 0;
			}
	
	for (row = 1; row <= maxrow; row ++ )
		for (col = 1; col <= maxcol; col ++ )
			grid[row][col] = new_grid[row][col];
}

void Life::print()
/* Pre: The Life object contains a configuration.
   Post: The configuration is written for the user.*/
{
	int row, col;
	cout << "\nThe current Life configuration is:" << endl;
	for (row = 1; row <= maxrow; row ++ )
	{
		for (col = 1; col <= maxcol; col ++ )
		{	
			if (grid[row][col] == 1) cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
}