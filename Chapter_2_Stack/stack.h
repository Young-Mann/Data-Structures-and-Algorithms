const int maxstack = 10010;
enum Error_code{success, underflow, overflow};
class Stack {
public:
	Stack();
	bool empty() const;
	Error_code push(const Stack_entry &item);
	Error_code top(Stack_entry &item) const;	
	Error_code pop();
	
private:
	int count;
	Stack_entry entry[maxstack];
};