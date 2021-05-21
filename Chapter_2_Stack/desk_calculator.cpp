
typedef double Stack_entry;
#include <iostream>
using namespace std;

#include "stack.h"
#include "stack.cpp"

#include "auxiliary.cpp"
#include "command.cpp"

int main()
/* Post: The program has executed simple arithmetic commands entered by the user.
   Uses: The class Stack, command.cpp and auxiliary.cpp. 
*/
{
	Stack stored_numbers;
	introduction();
	instructions();
	while(do_command(get_command(), stored_numbers));
}
