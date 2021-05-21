const int maxsize = 10;

class Double_stack {
public:
	Double_stack();
	bool empty_a() const;
	bool empty_b() const;
	bool fill() const;
	Error_code push_a(const Stack_entry &item);
	Error_code push_b(const Stack_entry &item);
	Error_code copy_top_a(Stack_entry &item) const;
	Error_code copy_top_b(Stack_entry &item) const;
	Error_code pop_a();
	Error_code pop_b();
	
private:
	int top_a, top_b;
	Stack_entry entries[maxstack];

}