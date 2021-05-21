
void introduction()
{
	cout << "This program implements a reverse Polish calulator." << endl
		 << "=====================================================" << endl;
}

void instructions()
{
	cout << "The valid caculator commands are:" << endl
				 << "===  [?] push to stack | [=] print top" << endl
				 << "=== [+] | [-] | [*] | [/] are arithmetic operators" << endl
				 << "=== e[X]change the top two stack entries" << endl
				 << "=== adjoin the [S]um of the stack entries" << endl
				 << "=== adjoin the [M]ean of the stack entries" << endl
				 << "=== [Q]uit." << endl;
}

bool do_command(char command, Stack &numbers)
/* Pre: The first parameter specifies a valid calculator command. 
   Post: The command specified has been applied to the Stack of numbers.
		 A result of true will be returned until the user enters a "q".
   Uses: The class Stack.
*/
{
	double p, q;
	int count;
	switch (command)
	{
		case '?':
			cout << "Enter a real number: " << endl;
			cin >> p;
			if (numbers.push(p) == overflow)
				cout << "Warning: Stack full, lost number." << endl;
			break;
			
		case '=':
			if (numbers.top(p) == underflow)
				cout << "Stack empty!" << endl;
			else
				cout << p << endl;
			break;
			
		case '+':
			if (numbers.top(p) == underflow)
				cout << "Stack empty!" << endl;
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has only one entry." << endl;
					numbers.push(p);
				}
				
				else
				{
					numbers.pop();
					if (numbers.push(q + p) == overflow)
						cout << "Warning: Stack full, lost result." << endl;
				}
				
			}
			break;
		
		case '-':
			if (numbers.top(p) == underflow)
				cout << "Stack empty!" << endl;
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has only one entry." << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(q - p) == overflow)
						cout << "Warning: Stack full, lost result." << endl;
				}
				
			}
			break;
			
		case '*':
			if (numbers.top(p) == underflow)
				cout << "Stack empty!" << endl;
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has only one entry." << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(q * p) == overflow)
						cout << "Warning: Stack full, lost result." << endl;
				}
				
			}
			break;
		
		case '/':
			if (numbers.top(p) == underflow)
				cout << "Stack empty!" << endl;
			else if (p == 0.0)
			{
				cerr << "Division by 0 fails; no action done." << endl;
				numbers.push(p);
			}
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has only one entry." << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(q / p) == overflow)
						cout << "Warning: Stack full, lost result." << endl;
				}
				
			}
			break;
			
		case 'x':
			if (numbers.top(p) == underflow)
				cout << "Stack empty!" << endl;
			
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has only one entry." << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(p) == overflow)
						cout << "Warning: Stack full, lost result." << endl;
					if (numbers.push(q) == overflow)
						cout << "Warning: Stack full, lost result." << endl;
				}
				
			}
			break;	
			
		case 's':
			p = sum_stack(numbers);
			if (numbers.push(p) == overflow)
				cout << "Warning: Stack full, lost result." << endl;
			break;
			
		case 'm':
			p = sum_stack(numbers);
			count = count_stack(numbers);
			if (count <= 0)
				cout << "Warning: Stack empty, lost result." << endl;
			else if (numbers.push(p / (double) count) == overflow)
				cout << "Warning: Stack full, lost result." << endl;
			break;
			
			
		case 'q':
			cout << "Calculation finished." << endl;
			return false;
	}
	return true;
}

char get_command()
/* Post: Get a legal input from the user. */
{	
	char command;
	bool waiting = true;
	while (waiting)
	{
		cin >> command;
		command = tolower(command);
		if (command == '+' || command == '-' || command == '*' || 
			command == '/' || command == '=' || command == 'q' ||
			command == '?' || command == 'x' || command == 's' ||
			command == 'm')
			waiting = false;
		else
		{
			cout << "Please enter a valid command" << endl
				 << "[?] push to stack | [=] print top" << endl
				 << "[+] | [-] | [*] | [/] are arithmetic operators" << endl
				 << "e[X]change the top two stack entries" << endl
				 << "adjoin the [S]um of the stack entries" << endl
				 << "adjoin the [M]ean of the stack entries" << endl
				 << "[Q]uit." << endl;
		}
		
	}
	return command;
}


