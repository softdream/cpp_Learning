#include < iostream >
#include < fstream >

#include <vector>

using namespace std;

struct A
{
	using T = int;

	int a;
	double b;

	std::vector<int> vec;
};


int main()
{
	A    a;
	A    b;

	ofstream fout(" out.bin ", ios::binary | ios::out);

	a.a = 1; 
	a.b = 3.1415;
	a.vec.push_back(10);
	a.vec.push_back(20);
	a.vec.push_back(30);

	fout.write(reinterpret_cast<char *>(&a.a), sizeof( a.a ) );
	fout.write(reinterpret_cast<char *>(&a.b), sizeof(a.b));
	fout.write(reinterpret_cast<char *>( a.vec.data() ), a.vec.size() * sizeof( a.vec.front() ));

	fout.close();
	
	b.vec.resize( a.vec.size() );// 一定要先分配内存，否则会报错。

	ifstream fin(" out.bin ", ios::binary );
	fin.read( (char *)&b.a, sizeof(b.a) );
	fin.read((char *)&b.b, sizeof(b.b));
	fin.read(reinterpret_cast<char *>(b.vec.data()), a.vec.size() * sizeof(a.vec.front()));

	std::cout << "b.a = " << b.a << std::endl;
	std::cout << "b.b = " << b.b << std::endl;
	
	for (auto it : b.vec) {
		std::cout << it << std::endl;
	}

	fin.close();
	return 0;
}
