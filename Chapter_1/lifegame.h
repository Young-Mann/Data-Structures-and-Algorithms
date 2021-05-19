const int maxrow = 10, maxcol = 10;

class Life {
public:
	void initialize();
	void print();
	void update();
private:
	int grid[maxrow + 2][maxcol + 2];
	int neighbor_count(int row, int col);
};

void instructions();
bool user_says_yes();