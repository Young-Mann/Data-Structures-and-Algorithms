
Stack::Stack()
/* Pre: None.
   Posr: The stack is initialized to be empty. */
{
	count = 0;
}

bool Stack::empty() const
/* Pre: None.
   Post: Return "true" if the stack is empty. Otherwise "false" is returned. */
{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}

Error_code Stack::push(const Stack_entry &item)
/* Pre: None.
   Post: If the Stack is not full, an item will be added to the top of the Stack. Otherwise an Error_code "overflow" is returned. */
{
	Error_code outcome = success;
	if (count >= maxstack)
		outcome = overflow;
	else
		entry[count ++ ] = item;
	return outcome;
}



Error_code Stack::top(Stack_entry &item) const
/* Pre: None.
   Post: If the Stack is not empty, an item will be added to the top of the Stack. Otherwise an Error_code "overflow" is returned. */
{
	Error_code outcome = success;
	if (count == 0) 
		outcome = underflow;
	else
		item = entry[count - 1];
	return outcome;
}

Error_code Stack::pop()
/* Pre: None.
   Post: If the Stack is not empty, the top of the Stack will be removed. */
{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else
		count --;
	return outcome;
}