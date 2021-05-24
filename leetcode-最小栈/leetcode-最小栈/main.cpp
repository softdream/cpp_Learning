#include <iostream>
#include <vector>
#include <algorithm>

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int val) {
		vec.push_back(val);
	}

	void pop() {
		vec.pop_back();
	}

	int top() {
		return vec.back();
	}

	int getMin() {
		int min = vec[0];
		for (size_t i = 1; i < vec.size(); i++) {
			if (min > vec[i]) min = vec[i];
		}
		return min;
	}

private:
	std::vector<int> vec;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

int main()
{
	MinStack *obj = new MinStack();

	obj->push( 1 );

	return 0;
}