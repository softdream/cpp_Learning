#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include <assert.h>
#include <iomanip>

template <typename Type>
Type stringToNum(const std::string &str)
{
	std::stringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

class Student {
public:
	Student() {

	}

	Student(int num_, std::string name_, \
		int age_, int math_, int english_, \
		int chinese_) : num(num_),
						name(name_),
						age(age_),
						math(math_),
						english(english_),
						chinese(chinese_)
	{

	}
						

	~Student() {

	}

	void setArg(int num_, std::string name_, \
		int age_, int math_, int english_, \
		int chinese_)
	{
		num = num_;
		name_ = name_;
		age = age_;
		math = math_;
		english = english_;
		chinese = chinese_;
	}

	double average()
	{
		return ( ( double )(math + english + chinese) / 3.0);
	}
private:
	int num;
	std::string name;
	int age;
	int math;
	int english;
	int chinese;
};

int main()
{
	std::ofstream outfile("STUD.DAT", std::ios::app);
	//assert(outfile.is_open());

	for (int i = 0; i < 5; i++) {
		std::string str;
		std::getline( std::cin, str );

		std::string nums = str.substr( str.find( "(" ) + 1, 1);
		//std::cout << "nums = " << nums << std::endl;
		int num = stringToNum<int>(nums);
		str.erase(0, str.find("(") + 1);

		std::string name = str.substr( str.find( "'" ) + 1, 1 );
	//	std::cout << "name = " << name << std::endl;
		str.erase( 0, str.find("'") + 1);

		std::string ages = str.substr( str.find( "," ) + 1, 2 );
		//std::cout << "ages = " << ages << std::endl;
		int age = stringToNum<int>(ages);
		str.erase( 0, str.find(",") + 1);

		std::string maths = str.substr(str.find(",") + 1, 2);
		//std::cout << "maths = " << maths << std::endl;
		int math = stringToNum<int>(maths);
		str.erase(0, str.find(",") + 1);

		std::string englishs = str.substr(str.find(",") + 1, 2);
		//std::cout << "englishs = " << englishs << std::endl;
		int english = stringToNum<int>(englishs);
		str.erase(0, str.find(",") + 1);

		std::string chineses = str.substr(str.find(",") + 1, 2);
		//std::cout << "chineses = " << chineses << std::endl;
		int chinese = stringToNum<int>(chineses);
		str.erase(0, str.find(",") + 1);

		Student stu( num, name, age, math, english, chinese);
		double ave = stu.average();
		//std::cout << "average = " << ave << std::endl;

		outfile << num << " " << name << " " << ave << std::endl;
	}

	outfile.close();

	std::ifstream infile;
	infile.open("STUD.DAT", std::ios::app);
	//assert(infile.is_open());

	std::string s;
	while (std::getline(infile, s)) {
		std::cout << s << std::endl;
	}

	infile.close();

	return 0;
}