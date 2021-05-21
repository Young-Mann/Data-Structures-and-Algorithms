

double sum_stack(Stack &numbers)
{
	double p, sum = 0.0;
	Stack temp_copy;
	while (!numbers.empty())
	{
		numbers.top(p);
		temp_copy.push(p);
		sum += p;
		numbers.pop();
	}
	
	while (!temp_copy.empty())
	{
		temp_copy.top(p);
		numbers.push(p);
		temp_copy.pop();
	}
	return sum;
}

int count_stack(Stack &numbers)
{
	double p;
	int counter = 0;
	Stack temp_copy;
	while (!numbers.empty())
	{
		numbers.top(p);
		temp_copy.push(p);
		counter ++ ;
		numbers.pop();
	}
	
	while (!temp_copy.empty())
	{
		temp_copy.top(p);
		numbers.push(p);
		temp_copy.pop();
	}
	return counter;
}