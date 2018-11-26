
#include<iostream>
using namespace std;

class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		_array = new int[k];
		_capacity = k;
		_size = 0;
		_left = 0;
		_right = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (!isFull())
		{
			_array[_right ] = value;
			_right = (_right + 1) % _capacity;
			_size++;
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (!isEmpty())
		{
			_left = (_left + 1) % _capacity;
			_size--;
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Get the front item from the queue. */
	int Front() {
		return _array[_left];
	}

	/** Get the last item from the queue. */
	int Rear() {
		return _array[(_left+_size-1)%_capacity];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if (_size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if (_capacity == _size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void PrintQueue()
	{
		int i = _left;
		int k = 0;
		while ( k < _size)
		{
			cout << _array[i] << " ";
			i = (i + 1) % _capacity;
			k++;
		}
	}
	~MyCircularQueue()
	{
		delete[] _array;
		_array = NULL;
	}
private:
	int *_array;
	int _capacity;
	int _left;
	int _size;
	int _right;
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue obj = new MyCircularQueue(k);
* bool param_1 = obj.enQueue(value);
* bool param_2 = obj.deQueue();
* int param_3 = obj.Front();
* int param_4 = obj.Rear();
* bool param_5 = obj.isEmpty();
* bool param_6 = obj.isFull();
*/

int main()
{
	MyCircularQueue q(3);
	cout<<q.isEmpty()<<endl;
	cout << q.enQueue(1) << endl;
	cout << q.enQueue(2) << endl;
	cout << q.enQueue(3) << endl;
	q.PrintQueue();
	cout << q.isFull() << endl;
	cout << q.Front();
	cout << " ";
	cout << q.Rear() << endl;
	cout << q.deQueue() << endl;
	q.PrintQueue();
	cout << q.Front();
	cout << " ";
	cout << q.Rear() << endl;
	system("pause");
	return 0;
}