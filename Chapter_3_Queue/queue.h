const int maxqueue = 10;

class Queue {
public；
	queue();
	bool empty() const;
	Error_code append(const Queue_entry &item);
	Error_code serve();
	Error_code retrieve(Queue_entry &item) const;
protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
}


class Extended_queue: public Queue {
public:
	bool full() const;
	void clear();
	int size() const;
	Error_code serve_and_retrieve(Queue_entry &item);
}