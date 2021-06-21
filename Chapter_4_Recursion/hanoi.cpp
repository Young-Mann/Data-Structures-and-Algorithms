// Solve the problem of Hanoi.
#include <iostream>
#include <ctime>
using namespace std;
clock_t start, stop;
long double duration, ans;

// const int disks = 4;
int disks, MAX_N = 30;

void move(int count, int start, int end, int temp);
/* Pre: None.
   Post: The simulation of the Towers of Hanoi has terminated. */


int main()
{	
	for (int i = 1; i < MAX_N; i ++ )
	{
		start = clock();
		move(i, 1, 3, 2);
		stop = clock();
		duration = ((double)(stop - start)) / CLK_TCK;
		cout <<  "The duration of " << i << " disks is : "<< duration << "." << endl;
		
	}
	
	return 0;
}


void move(int count, int start, int end, int temp)
{
	if (count > 0)
	{
		move(count - 1, start, temp, end);
		// cout << "Move disk " << count << " from " << start
		// 	    << " to " << end << "." << endl;
		move(count - 1, temp, end, start);
	}
}