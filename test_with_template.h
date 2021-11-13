/*
    tests.cpp

    Tests for the Queue class.

    Code for CSCI 262 lab 12 - Queues

    Author: L. Henke
*/

#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;

int NUM_PASSED = 0;
int NUM_TESTED = 0;

void test_true(bool expr, string desc) {
    NUM_TESTED ++;
    
    if (!expr) {
        cerr << "FAILED test: ";
        cerr << '"' << desc << '"' << endl;
    } else {
        NUM_PASSED++;
    }
}

void print_results() {
    cout << NUM_PASSED << "/" << NUM_TESTED << " tests passed" << endl;
    cout << "Missed " << NUM_TESTED - NUM_PASSED << endl << endl;

    NUM_TESTED = 0;
    NUM_PASSED = 0;
}

void run_tests() {
    Queue<char> q;
    int num_chars_added_to_queue = 100000;

    // constructor test
    test_true(q.is_empty(), "Queue is initially empty.");

    // Test circularness
    for (size_t i = 0; i < 10; i++) {
        q.enqueue((char) i);

        test_true(q.front() == (char) i, "Queue enqueues correctly");

        q.dequeue();
    }

    test_true(q.is_empty(), "Queue is empty after enqueuing and dequeuing 10 elements");

    // Test proper dynamic allocation
    for (size_t i = 0; i < 50; i++) {
        q.enqueue((char) i);
    }

    test_true(q.front() == 0, "Queue enqueues first element");
    test_true(!q.is_empty(), "Queue is not empty after enqueue");
    test_true(q.size() == 50, "Queue enqueues 50 elements");

    for (size_t i = 50; i < 150; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == 150, "Queue enqueues 150 elements");

    for (size_t i = 150; i < 250; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == 250, "Queue enqueues 250 elements");

    for (size_t i = 250; i < 1000; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == 1000, "Queue enqueues 1000 elements");

    for (size_t i = 1000; i < 2000; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == 2000, "Queue enqueues 2000 elements");

    for (size_t i = 2000; i < 3000; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == 3000, "Queue enqueues 3000 elements");

    for (size_t i = 3000; i < 5000; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == 5000, "Queue enqueues 5000 elements");

    for (size_t i = 5000; i < 10000; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == 10000, "Queue enqueues 10000 elements");

    for (size_t i = 10000; i < num_chars_added_to_queue; i++) {
        q.enqueue((char) i);
    }
    test_true(q.size() == num_chars_added_to_queue, "Queue enqueues " + to_string(num_chars_added_to_queue) + " elements");


    // dequeue all the elements
    for (size_t i = 0; i < num_chars_added_to_queue; i++) {
        q.dequeue();
    }

    test_true(q.is_empty(), "Queue is empty after entire dequeue.");

    print_results();

    Queue<char> queue;

    // First, check equality
    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');
    queue.enqueue('d');
    queue.enqueue('e');
    Queue<char> c;
    c = queue;

    test_true(c.size() == 5, "Size of queue is the same after equal overload");
    test_true(c.front() == 'a', "Queue front element is the same after equal overload");

    c.dequeue();
    c.dequeue();
    c.enqueue('g');
    c.enqueue('h');
    c.enqueue('i');
    c.enqueue('j');
    c.enqueue('k');
    c.enqueue('l');

    test_true(c.front() == 'c', "Assignment front element is 'b'.");
    test_true(c.size() == 9, "Assignment queue has correct size");
    test_true(queue.front() == 'a', "Assignment and changes does not modify original queue front().");
    test_true(queue.size() == 5, "Assignment and change does not modify original queue size");

    queue.dequeue();
    queue.enqueue('9');

    test_true(c.size() == 9, "Modifications to original queue doesn't effect Assignment queue size");
    test_true(c.front() == 'c', "Modifications to original queue doesn't effect Assignment queue front()");

    // Then, check copy constructor
    Queue<char> d(queue);

    test_true(d.size() == 5, "Size of queue is the same after copy constructor");
    test_true(d.front() == 'b', "Queue front element is the same after copy constructor");

    // Force d to expand, which will effect `queue` if not done correctly
    d.dequeue();
    d.dequeue();
    d.dequeue();
    d.dequeue();
    d.dequeue();

    d.enqueue('!');
    d.enqueue('@');
    d.enqueue('#');
    d.enqueue('$');
    d.enqueue('%');
    d.enqueue('^');
    d.enqueue('&');
    d.enqueue('*');
    d.enqueue('(');

    test_true(d.front() == '!', "Copied queue behaves correctly");
    test_true(queue.size() == 5, "Changing copy constructor size doesn't effect original queue size");
    test_true(queue.front() == 'b', "Changing copy constructor front() doesn't effect original queue front()");

    queue.dequeue();
    queue.enqueue('m');

    d.enqueue('p');
    test_true(queue.size() == 5, "Copy and change does not modify original queue size()");
    test_true(queue.front() == 'c', "Copy and change does not modify original queue front()");

    print_results();

    NUM_PASSED=0;
    Queue<int> i;

    i.enqueue(1);
    i.enqueue(2);
    i.enqueue(3);
    i.enqueue(4);
    i.enqueue(5);
    test_true(i.front() == 1, "Queue's front() element is correct");

    Queue<double> j;
    j.enqueue(1.0);
    j.enqueue(2.0);
    j.enqueue(3.0);
    j.enqueue(4.0);
    j.enqueue(5.0);
    test_true(j.front() == 1.0, "Queue's front() element is correct");

    print_results();
}
