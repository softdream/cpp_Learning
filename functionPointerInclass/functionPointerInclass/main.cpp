#include <iostream>
#include <functional>
using namespace std::placeholders;

typedef std::function<void*(int, void*)> Fun;

typedef struct {
	int fd;// the fd want to monitor
	short event;// the event want to monitor
				//void *( *callback )( int fd, void *arg );// the callback function
	Fun callbcak;
	void *arg;// the parameters of the callback function
}Event;

class Test
{
public:
	Test()
	{
		event.fd = 1;

		Fun fun = std::bind( &Test::Callback, this, _1, _2 );
		event.callbcak = fun;
	}

	void *Callback(int fd, void *arg)
	{

	}

private:
	Event event;
};

int main()
{

	return 0;
}