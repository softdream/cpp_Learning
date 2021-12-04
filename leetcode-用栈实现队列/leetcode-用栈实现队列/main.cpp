#include <vector>
#include <iostream>
#include <stack>

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() 
	{

	}

	/** Push element x to the back of queue. */
	void push(int x) 
	{
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() 
	{
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
	}

	/** Get the front element. */
	int peek() {

	}

	/** Returns whether the queue is empty. */
	bool empty() 
	{

	}


private:
	std::stack<int> s1;
	std::stack<int> s2;
};

int main()
{

	return 0;
}
