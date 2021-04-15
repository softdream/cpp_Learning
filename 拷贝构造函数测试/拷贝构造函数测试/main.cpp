#include <iostream>

typedef struct {
	int d;
	int e;
}Type;

/*class Base {
private:
	int a;
	int b;
	Type t;
	int *c;
public:
	Base() : a(1), b(2)
	{
		t.d = 10;
		t.e = 20;
		std::cout << "a = " << a << std::endl;
		std::cout << "t.d = " << t.d << std::endl;
		c = new int[10];
		for (int i = 0; i < 10; i++) {
			c[i] = i;
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		}

	}
	Base(Base &obj) :a(obj.a), b(obj.b)
	{
		t.d = obj.t.d;
		t.e = obj.t.e;
		std::cout << "t.d = " << t.d << std::endl;
		std::cout << "a = " << a << std::endl;
		c = new int[10];
		*c = *(obj.c);
		for (int i = 0; i < 10; i++) {
			c[i] = i;
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		}
	}

	~Base()
	{
		delete[] c;
	}
};


int main()
{
	Base b;
	std::cout << "--------------------------------" << std::endl;
	Base c(b);
	return 0;
}
*/

class Base {
private:
	int a;
	int b;
	Type  *t;
public:
	Base(): a(1), b(2)
	{
		std::cout << "a = " << a << std::endl;
		t = new Type[10];
		t[0].d = 10;
		t[0].e = 20;
	}

	Base& operator=(const Base &other)
	{
		if (this == &other) return *this;// ¼ì²â×Ô¸³Öµ
		t = new Type[10];
		*t = *(other.t);
		return *this;
	}

	Base(Base &obj):a( obj.a ), b( obj.b )
	{
		t = new Type[10];
		*t = *( obj.t );
		std::cout << "t[0].d = " << t[0].d << std::endl;
		std::cout << "t[0].e = " << t[0].e << std::endl;
	}
	~Base() {
		delete[] t;
	}
};

int main()
{
	Base b;
	Base c = b;
	return 0;
}