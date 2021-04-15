#include <iostream>
#include <vector>

class Subject;

class Observer
{
public:
	virtual void update(Subject* sub, int value) = 0;
};

class Subject
{
	int m_value;

	std::vector<Observer*> m_views;

public:
	void attach(Observer* obs) // ¶©ÔÄ
	{
		m_views.push_back(obs);
	}

	void set_value(int value)
	{
		m_value = value;
		notify();
	}

	void notify() //·¢²¼
	{
		for (int i = 0; i < m_views.size(); ++i) {
			m_views[i]->update( this, m_value );
		}
	}
};

int main()
{
	return 0;
}