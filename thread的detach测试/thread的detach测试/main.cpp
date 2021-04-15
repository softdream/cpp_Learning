#include <iostream>
#include <thread>
#include <Windows.h>
#include <map>
#include <vector>

#define INET_ADDRSTRLEN 16
#define TOPICNAMELEN 30

typedef enum{
        publisher = 1,
        subscriber
}TopicType;


/* Sub-Pub Node Information */
struct TopicInfo{
        TopicInfo(){}

        TopicInfo( const TopicInfo &obj ): port( obj.port ),
                                           topicType( obj.topicType ),
                                           head1( obj.head1 ),
                                           head2( obj.head2 ),
                                           udpPort( obj.udpPort )
        {
                memcpy( topicName, obj.topicName, TOPICNAMELEN );
                memcpy( ipAddr, obj.ipAddr, INET_ADDRSTRLEN );
        }

        TopicInfo& operator=( const TopicInfo &other )
        {
                if( this == &other )
                        return *this;
                head1 = other.head1;
                head2 = other.head2;
                port = other.port;
                udpPort = other.udpPort;
                topicType = other.topicType;
                memcpy( topicName, other.topicName, TOPICNAMELEN );
                memcpy( ipAddr, other.ipAddr, INET_ADDRSTRLEN );

                return *this;
        }

        ~TopicInfo(){}

        char head1;
        char head2;
        char topicName[ TOPICNAMELEN ];
        int port;
        char ipAddr[ INET_ADDRSTRLEN ];
        TopicType topicType;
        int udpPort;
};
typedef struct TopicInfo TopicInfo;

class A {
public:
	A():number(0)
	{

	}

	void testA()
	{
		while (1) {
			
			Sleep( 1000 );
			number++;
			std::cout << "thread1 ..." << number << std::endl;
		}
	}

	int getNumber()
	{
		return number;
	}

private:
	int number;
};

class B {
public:
	A testB()
	{
		A a;
		table.insert( std::make_pair("d", a) );
		//std::thread t1( &A::testA, &a );

		auto it = table.find("d");
		std::thread t1( &A::testA, it->second );

		t1.detach();
		return a;
	}

private:
	std::map<std::string, A> table;
	//std::vector<A> table;

};

int main()
{
	/*B b;
	A a = b.testB();

	while (1) {
		std::cout << "main thread " << a.getNumber() << std::endl;
		Sleep( 2000 );
	}*/

	std::cout << "sizeof ( TopicInfo ) = " << sizeof(TopicInfo) << std::endl;

	return 0;
}