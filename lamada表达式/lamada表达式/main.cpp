#include <iostream>
#include <vector>

using namespace std;

struct print{ 
	void operator()( int element )
	{
		cout << element << endl; 
	}
}; 
int main(void) 
{ 
	std::vector<int> v = { 1, 2, 3, 4, 5 }; 
	std::for_each( v.begin(), v.end(), print() );
	return 0;
}