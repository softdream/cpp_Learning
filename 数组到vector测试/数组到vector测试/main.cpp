#include <iostream>
#include <vector>

class Particle
{
public:
	Particle()
	{

	}

	~Particle()
	{

	}

	const float getWeight() const 
	{
		return weight;
	}
private:
	// state variable
	float x = 10;
	float y = 20;
	float theta = 3.14;

	// weight       
	float weight =100;
};

int main()
{
	Particle t[10];


	std::vector<Particle> t_c( t, t + 10 );

	for (auto it : t_c) {
		std::cout << "weight = " << it.getWeight() << std::endl;
	}

	return 0;
}
