#include <iostream>
#include <thread>


template <typename T>
class Publisher {
public:
	Publisher()
	{
		std::cout << "constructure ..." << std::endl;
	}
	~Publisher()
	{

	}
	Publisher( const Publisher& obj): data(obj.data)
	{
		std::cout << "copy constructure ..." << std::endl;
	}

	Publisher& operator=(const Publisher& other)
	{
		std::cout << "agin constructure ..." << std::endl;
		data = data;
	}

	void setData( T &data_ )
	{
		data = data_;
	}

	void setData( T data_)
	{
		data = data_;
	}
	void publish()
	{
		std::cout <<"data = "<< data << std::endl;
	}
private:
	T data;
};

template<typename T>
Publisher<T> advertise()
{
	Publisher<T> pub;
	pub.setData( 1000 );
	return pub;
}

int main()
{
	Publisher<int> pub = advertise<int>();

	pub.publish();
	return 0;
}