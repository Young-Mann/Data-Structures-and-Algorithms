// Compute the fatorial.
#include <iostream>
#include <ctime>
using namespace std;
clock_t start, stop;
long double duration, ans;

int n = 5;
const int MAX_N = 1e4;

int compute_factorial_recur(int n)
{
	if (n == 0 || n == 1) {
		return 1;
	}
	
	return n * compute_factorial_recur(n - 1);
}

int compute_factorial_iter(int n)
{
	int res = 1;
	while (n) {
		res *= n;
		n -- ;
	}
	return res;
}


int main()
{
	start = clock();
	for (int i = 0; i < MAX_N; i ++ )
		ans = compute_factorial_recur(MAX_N);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAX_N;
	
	cout << "The result of recursion: " << ans << endl;
	cout << "It took " << duration << " to finish the recursion." << endl;
	
	start = clock();
	for (int i = 0; i < MAX_N; i ++ )
		ans = compute_factorial_iter(MAX_N);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAX_N;
	
	cout << "The result of iter: " << ans << endl;
	cout << "It took " << duration << " to finish the iteration." << endl;
}
