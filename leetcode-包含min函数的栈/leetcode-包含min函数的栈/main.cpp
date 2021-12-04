#include <iostream>
#include <vector>

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		vec.push_back(x);
	}

	void pop() {
		if( !vec.empty() )
			vec.pop_back();
	}

	int top() {
		return vec.back();
	}

	int min() {
		int min = vec[0];
		
		for (auto it : vec) {
			if (min > it) {
				min = it;
			}
		}

		return min;
	}

	void printVec()
	{
		std::cout << "Vector " << std::endl;
		for (auto it : vec) {
			std::cout << it << std::endl;
		}
	}

private:
	std::vector<int> vec;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/

int main()
{
	MinStack* obj = new MinStack();
	
	obj->push(2);
	obj->push(0);
	obj->push(3);
	obj->push(0);
	obj->printVec();

	std::cout <<"min: "<< obj->min() << std::endl;
	obj->pop();
	obj->printVec();
	std::cout << "min: " << obj->min() << std::endl;
	
	obj->pop();
	obj->printVec();
	std::cout << "min: " << obj->min() << std::endl;

	obj->pop();
	obj->printVec();
	std::cout << "min: " << obj->min() << std::endl;

	return 0;
}