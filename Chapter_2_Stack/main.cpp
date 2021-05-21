// Page 65, programming projects 2.2
typedef int Stack_entry;


#include <iostream>
using namespace std;

#include "stack.h"
#include "stack.cpp"

int main()
/* Pre: The user supplies a positive integer n.
   Post: The prime factors of n are printed in descending order.
   Uses: The class "Stack" and its methods. */
{
	int n, origin_num;
	Stack numbers;
	
	cout << "Type in a positive integer n, whose prime factors will be printed on the screen." << endl;
	cin >> n; // 114514
	origin_num = n;
	
	int divisor = 2;
	while (n > 1)
	{
		if (n % divisor)
			divisor ++ ;
		else
		{
			n /= divisor;
			cout << n << "   divisor:" << divisor << endl;
			// 57257   divisor:2
			// 1847   divisor:31
			// 1   divisor:1847

			if (numbers.push(divisor) != success)
				cout << "Warning: Stack Overflow occured." << endl;
		}
	}
	
	cout << "\nThe prime factors of " << origin_num << " are: " << endl;
			// The prime factors of 114514 are:
			// 1847 31 2
			
	while (!numbers.empty())
	{
		int factor;
		numbers.top(factor);
		numbers.pop();
		cout << factor << " ";
	}
	cout << endl;
}