#ifndef _QUEUE_H
#define _QUEUE_H

/*
    Queue.h

    A working implementation of a fixed-size circular queue
    meeting the requirements of the Queue, part 1 lab.  Use
    or replace as you wish.
*/

class Queue {
public:
	// max elements in queue
	static const unsigned int ARRAY_SZ = 5;

    // constructor
	Queue() { _front = 0; _back = 0; _size = 0; }

    // enqueue: add a char to the end of the queue if room and return true;
    // if not enough room, return false
	bool enqueue(char c) {
        if (_size == ARRAY_SZ) return false;
		_data[_back] = c;
		_back = (_back + 1) % ARRAY_SZ;
        _size++;
		return true;
	}

    // dequeue: if queue is not empty, remove the front element from the queue;
    // if queue is empty, return false and do nothing.
	bool dequeue()  {
		if (is_empty()) return false;
		_front = (_front + 1) % ARRAY_SZ;
        _size--;
		return true;
	}

    // front: return the front element in the queue
	char front()    { return *_data[_front]; }

    // is_empty: return whether or not the queue is empty
	bool is_empty() { return _size == 0; }

	int size() {
		return _size;
	}

private:
	char* _data[5] = {};
    int  _size;
	int  _front;
	int  _back;

};

#endif
