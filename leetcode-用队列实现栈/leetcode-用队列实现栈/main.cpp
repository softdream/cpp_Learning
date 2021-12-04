#include <iostream>
#include <queue>

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack()
	{

	}

	/** Push element x onto stack. */
	void push(int x)
	{
		q1.push( x );
		int size = q1.size();

		for (int i = 0; i < size; i++) {
			q1.push( q1.front() );
			q1.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		int ret = q1.front();

		q1.pop();
		return ret;
	}

	/** Get the top element. */
	int top() 
	{
		return q1.front();
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return q1.empty();
	}


private:
	std::queue<int> q1;

};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/

int main()
{
	MyStack* obj = new MyStack();
	obj->push(1);
	obj->push(2);
	obj->push(3);

	int param_2 = obj->pop();
	std::cout << "param2 = " << param_2 << std::endl;

	int param_3 = obj->top();
	std::cout << "param3 = " << param_3 << std::endl;

	return 0;
}