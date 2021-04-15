#include <iostream>
#include <functional>
#include <map>
#include <memory>
#include <typeinfo>
#include <vector>

std::shared_ptr<void> ptr;

std::vector<std::shared_ptr<void>> v;

int main()
{
	std::shared_ptr<int> sp( new int(7) );

	std::cout << "type of sp = " << typeid(sp).name() << std::endl;

	ptr = std::static_pointer_cast<void>( sp );
	v.push_back( ptr );

	std::cout << "type of ptr = " << typeid(ptr).name() << std::endl;

	auto it = v.begin();
	std::cout << "type of *it = " << typeid(*it).name() << std::endl;

	return 0;
}