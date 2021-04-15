#include "message_generate.h"


int main()
{
	readMessageInfo( "test.message" );
	writeMessageInfo("test.h");

	getMessageLists("test.h");
	return 0;
}