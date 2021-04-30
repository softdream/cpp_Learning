#include "messageParse.h"

using namespace serialize;

int main()
{
	std::string path = "my.message";

	Serialize s;

	s.setReadPath(path);

	s.read();

	s.elementsInfoPrintTest();

	return 0;
}