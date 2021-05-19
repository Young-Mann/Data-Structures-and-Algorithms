// quick_sort
// 1. 定义常量时，不一定要用宏，可以用const int
// 2. 注意边界条件是n-1
#include <iostream>
using namespace std;

const int MAXSIZE = 100000010;
int q[MAXSIZE];

void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;
	int i = l - 1, j = r + 1, x = q[(l+r)/2];
	
	while (i < j)
	{
		do i ++ ; while (q[i] < x);
		do j -- ; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
		
		quick_sort(q, l, j);
		quick_sort(q, j+1, r);
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	
	for (i = 0; i <n; i ++ )
		scanf("%d", &q[i]);
	
	quick_sort(q, 0, n-1);
}