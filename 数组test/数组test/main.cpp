#include <iostream>

int a[3][3] = { {1,2,3},{4, 5, 6},{7, 8, 9} };


void test(int b[][])
{
/*	for( int i = 0; i < 3; i ++ )
		std::cout << "b[0][" << i << "] = " << b[i] << std::endl;

	for (int i = 0; i < 3; i++)
		std::cout << "b[1][" << i << "]" << b[i + 3] << std::endl;

	for (int i = 0; i < 3; i++)
		std::cout << "b[2][" << i << "]" << b[i + 6] << std::endl;
*/
}

int main()
{
	test( &a[0][0] );

	return 0;
}