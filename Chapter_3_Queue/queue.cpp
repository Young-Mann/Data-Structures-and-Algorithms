Queue::Queue()
/* Post: The Queue is initialized to empty. */
{
	count = 0;
	rear = maxqueue - 1;
	front = 0;
}

bool Queue::empty()
/* Post: Return true if the queue is empty, otherwise return false. */
{
	return count == 0;
}

Error_code Queue::append(const Queue_entry &item)
/* Post: Add an item to the rear of the Queue, provided that the queue is not full. */
{
	if (count >= maxqueue) return overflow;
	rear = (rear+1) == maxqueue ? 0 : rear+1;
	entry[rear] = item;
	count ++ ;
	return success;
}

Error_code Queue::serve()
/* Post: Remove an item from the rear of the Queue, provided that the queue is not empty. */
{
	if (count <= 0) return underflow;
	rear = (front + 1) == maxqueue ? 0 : rear+1;
	count -- ;
	return success;
}

Error_code Queue::retrieve(Queue_entry &item) const
/* Post: The front of the Queue has been retrieved to the output parameter item. */
{
	if (count <= 0) return underflow;
	item = entry[front];
	return success;
}

Error_code Extended_queue::full() const
{
	return count == maxqueue;
}

Error_code Extended_queue::clear()
{
	count = 0;
	front = 0;
	rear = maxqueue - 1;
	return success;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item)
{
	if (count <= 0) return underflow;
	else {
		item = entry[front];
		count -- ;
		front = ((front + 1) == maxqueue) ? (front + 1) : 0;
	}
	return success;
}