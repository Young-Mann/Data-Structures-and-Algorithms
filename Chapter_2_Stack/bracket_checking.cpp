typedef char Stack_entry;
#include <iostream>
using namespace std;

#include "stack.h"
#include "stack.cpp"

int main()
/* Post: The program has notified the user of any bracket mismatch in the standard input file. 
   Uses: The class Stack. 
*/
{
	Stack openings;
	char current_bracket;
	bool is_matched = true;
	while (is_matched && (current_bracket = cin.get()) != '\n')
	{
		if (current_bracket == '(' || current_bracket == '[' || current_bracket == '{')
			openings.push(current_bracket);
		if (current_bracket == ')' || current_bracket == ']' || current_bracket == '}')
		{
			if (openings.empty())
			{
				cout << "Unmatched bracket" << current_bracket << "detected." << endl;
				is_matched = false;
			}
			
			else
			{
				char top_bracket;
				openings.top(top_bracket);
				openings.pop();
				is_matched = (top_bracket == '(' && current_bracket == ')') 
							 || (top_bracket == '[' && current_bracket == ']') 
							 || (top_bracket == '{' && current_bracket == '}');
				if (!is_matched) 
					cout << "Bad match: " << top_bracket << " and " << current_bracket << endl;
			}
		}
		
		
	}
	if (!openings.empty())
		cout << "Unmatched bracket(s) detected." << endl;
}