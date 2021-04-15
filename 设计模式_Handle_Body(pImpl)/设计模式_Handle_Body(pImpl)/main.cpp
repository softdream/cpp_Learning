#include <iostream>

/*
	Handle/Body
	Pointer To Implementation
*/

class StringRep;

class String
{
public:
	String()
	{

	}
	String(const char *s)
	{

	}
	String(const String& s)
	{

	}
	String& operator=(const String& s)
	{

	}

private:
	StringRep* rep;// pimpl , 两个类之间关系是通过指针复合的
};

class StringRep
{
	friend class String;
	StringRep(const char *s)
	{

	}

	int count;
	char* rep;
};


int main()
{

}
