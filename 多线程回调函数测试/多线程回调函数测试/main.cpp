#include <thread>
#include <functional>
#include <iostream>

char recvBuff[10] = { 'H', 'e', 'l','l', 'o', '!' };

template<typename T>
using CallBack = std::function<void(T)>;

template<typename T>
class Subscriber {
public:
	void recvCb()
	{
		std::cout << "recv callback ...." << std::endl;
		memset( &message, 0, sizeof( message ) );
		memcpy( &message, recvBuff, sizeof(message) );
		cb( message );

	}

	void createASubscriber()
	{
		std::cout << "Create A Subscriber ...." << std::endl;
	}

	void setCallbackFunction()
	{
		std::cout << "Set the Callback Function of the Subscriber ..." << std; :endl;

	}

private:
	T message;
	CallBack<T> cb;
};

class PCS {
public:
	template<typename T>
	void subscribe(std::string topicName, CallBack<T> &cb)
	{
		Subscriber<T> sub;

	}

private:

};




int main()
{
	std::cout << "Program Begins ..." << std::endl;
	return 0;
}


