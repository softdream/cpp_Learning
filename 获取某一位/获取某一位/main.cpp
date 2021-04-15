#include<iostream>

unsigned char getBit(unsigned char temp, int bit)
{
	return ((temp >> bit) & 0x01);
}

unsigned char A[20][24];


int main()
{
	unsigned char a = 56;
	std::cout << (int)getBit(a, 6) << std::endl;
	return 0;
}
