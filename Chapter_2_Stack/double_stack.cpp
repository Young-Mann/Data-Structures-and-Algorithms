// The implementation of the member functions in Class "Double_stack".

Double_stack::Double_stack()
/* Pre: None.
   Post: The Double_stack is initialized to empty. 
*/
{
	top_a = -1;
	top_b = maxstack;
}


bool empty_a() const
/* Pre: None.
   Post: If the a-stack of the Double_stack is empty, "true" is returned. Otherwises "false" is returned. 
*/
{
	return top_a <= -1;
}


bool empty_b() const
/* Pre: None.
   Post: If the b-stack of the Double_stack is empty, "true" is returned. Otherwises "false" is returned. 
*/
{
	return top_b >= maxstack;
}


bool full() const
/* Pre: None.
   Post: If the Double_stack is full, "true" is returned. Otherwises "false" is returned. 
*/
{
	return top_a >= top_b - 1;
}


Error_code push_a(const Stack_entry &item)
/* Pre: None.
   Post: If the Double_stack is not full, item is added to the top of the a-stack of Double_stack.
		 If the Double_stack is full, an Error_code of overflow is returned and the Double_stack
		 is left unchanged. 
*/
{
	if (top_a >= top_b − 1) return overflow;
	entry[ ++ top_a] = item;
	return success;
}


Error_code push_b(const Stack_entry &item)
/* Pre: None.
   Post: If the Double_stack is not full, item is added to the top of the b-stack of Double_stack.
		 If the Double_stack is full, an Error_code of overflow is returned and the Double_stack
		 is left unchanged. 
*/
{
	if (top_a >= top_b − 1) return overflow;
	entry[ -- top_b] = item;
	return success;
}


Error_code copy_top_a(Stack_entry &item) const
/* Pre: None.
   Post: If the b-stack of the Double_stack is not empty, its top is returned in item. Otherwise
		 an Error_code of underflow is returned. 
*/
{
	if (top_a == -1) return underflow;
	item = entry[top_a];
	return success;
	

Error_code copy_top_b(Stack_entry &item) const
/* Pre: None.
Post: If the b-stack of the Double_stack is not empty, its top is returned in item. Otherwise
an Error_code of underflow is returned. */
{
	if (top_b == maxstack) return underflow;
	item = entry[top_b];
	return success;
}


Error_code pop_a()
/* Pre: None.
   Post: If the b-stack of the Double_stack is not empty, its top is removed.
   Otherwise an Error_code of underflow is returned. 
*/
{
	if (top_a <= -1) return underflow;
	else -- top_a;
	return success;
}

Error_code pop_b()
/* Pre: None.
   Post: If the b-stack of the Double_stack is not empty, its top is removed.
   Otherwise an Error_code of underflow is returned. 
*/
{
	if (top_b >= maxstack) return underflow;
	else ++ top_b;
	return success;
}