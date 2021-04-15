#ifndef __TEST_H_
#define __TEST_H_

#include <string.h>

#ifndef unsigned char uint8_t
	#define unsigned char uint8_t
#ifndef char int8_t
	#define char int8_t
#ifndef unsigned int uint32_t
	#define unsigned int uint32_t
#ifndef int int32_t
	#define int int32_t
#ifndef float float32_t
	#define float float32_t
#ifndef unsigned float ufloat32_t
	#define unsigned float ufloat32_t
#ifndef long int64_t
	#define long int64_t
#ifndef unsigned long uint64_t
	#define unsigned long uint64_t
#ifndef double double64_t
	#define double double64_t
#ifndef unsigned double udouble64_t
	#define unsigned double udouble64_t

namespace pcs {

struct Test{
	uint8_t head1;
	uint8_t head2;
	int32_t message;
	uint8_t rear;

	int body[10];

	Test( )
	{

	}

	~Test( )
	{

	}

	Test( const Test &obj ): message( obj.message ), 
			head1( obj.head1 ), 
			head2( obj.head2 ), 
			rear( obj.rear ) 
	{
		memcpy( body, obj.body, 10 );

	}

	Test& operator=( const Test &other )
	{
		if( this == &other )
			return *this;
		message = other.message;
		head1 = other.head1;
		head2 = other.head2;
		rear = other.rear;
		memcpy( body, other.body, 10 );

		return *this;
	}

	Test( const int32_t message_, const uint8_t head1_, const uint8_t head2_, const uint8_t rear_  ): message( message_ ),
			head1( head1_ ),
			head2( head2_ ),
			rear( rear_ )
	{

	}

	inline int body_size()
	{
		int size = 10;
		return size; 
	}
};

typedef struct Test Test
}
#endif
