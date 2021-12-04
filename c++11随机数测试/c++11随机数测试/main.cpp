#include <iostream>
#include <random>

int main()
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen;

	gen.seed( rd() );

	std::uniform_real_distribution<float> rand( 0, 10 );

	float a1 = rand(gen);

	std::cout << "a1 = " <<a1<< std::endl;

	return 0;
}