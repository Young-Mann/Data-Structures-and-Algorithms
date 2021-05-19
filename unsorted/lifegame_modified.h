// Modifications:
// 1. Turn the "maxrow" and "maxcol" into member variables.
//	  Now the user has to pass 2 extra arguments to the function initialize().


const int maxrow_bound = 10, maxcol_bound = 10; // (1)

class Life {
public:
	void initialize();
	void print();
	void update();
private:
	int maxrow, maxcol;		// (1) New member variables.
	int grid[maxrow + 2][maxcol + 2];
	int neighbor_count(int row, int col);
};

void instructions();
bool user_says_yes();