#ifndef _QUEUE_H
#define _QUEUE_H

/*
    Queue.h

    A working implementation of a fixed-size circular queue
    meeting the requirements of the Queue, part 1 lab.  Use
    or replace as you wish.
*/
template <class T>
class Queue {
public:
	// max elements in queue
//	static const unsigned int ARRAY_SZ = 5;

    // constructor
	Queue() { _front = 0; _back = 0; _size = 0; _cap = 5; _data = new T[_cap];}
    Queue(const Queue &q){
        _front = q.front_back().first;
        _back = q.front_back().second;
        _size = q.size();
        _cap = q.capacity();
        _data = new T[_cap];
        for (int i = 0; i < _size; ++i) {
            _data[i] = q.array()[i];
        }
    }
    Queue& operator=(const Queue &q){
        if (this == &q) return *this;
        _front = q.front_back().first;
        _back = q.front_back().second;
        _size = q.size();
        _cap = q.capacity();
        _data = new T[_cap];
        for (int i = 0; i < _size; ++i) {
            _data[i] = q.array()[i];
        }
        return *this;
    }

    // enqueue: add a T to the end of the queue if room and return true;
    // if not enough room, return false
	void resize(int size){
        T* newarr = new T[size];
        int i = 0;
        while(_front != _back){
            newarr[i] = _data[_front];
            _front = (_front + 1) % _cap;
            i++;
        }
        newarr[i] = _data[_back];
        _front = 0;
        _back = _size - 1;
        delete[] _data;
        _data = newarr;
        _cap = size;
    }

    bool enqueue(T c) {
        if (_size == _cap){
            resize(_cap * 2);
        }
		_data[_back] = c;
		_back = (_back + 1) % _cap;
        _size++;
		return true;
	}

    // dequeue: if queue is not empty, remove the front element from the queue;
    // if queue is empty, return false and do nothing.
	bool dequeue()  {
		if (is_empty()) return false;
		_front = (_front + 1) % _cap;
        _size--;
		return true;
	}

    // front: return the front element in the queue
	T front()    { return _data[_front]; }

    // is_empty: return whether or not the queue is empty
	bool is_empty() { return _size == 0; }

    int capacity() const{
        return _cap;
    }

	int size() const {
		return _size;
	}
    std::pair<int,int> front_back() const{
        return {_front,_back};
    }
    //return a pointer to the underlying array;
    T* array() const{
        return _data;
    }
private:
	T* _data = new T[5];
    int  _size;
	int  _front;
	int  _back;
    int _cap;

};

#endif
