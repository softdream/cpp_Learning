#include<iostream>

typedef struct {
	int fd;// the fd want to monitor
	short event;// the event want to monitor
	void *(*callback)(int fd, void *arg);// the callback function
	void *arg;// the parameters of the callback function
}Event;

void *callback(int fd, void *arg)
{
	std::cout << "test1" << std::endl;
	
}

Event ev;
void test(void *(*cb)(int fd, void *arg))
{
	ev.callback = cb;
}

int main()
{
	test( callback );
	return 0;
}