#ifndef __DELEGATE_BASE_H_
#define __DELEGATE_BASE_H_

#include <typeinfo>

class IDelegate
{
public:
	virtual ~IDelegate() { }
	virtual bool isType(const std::type_info& _type) = 0;
	virtual void invoke() = 0;
	virtual bool compare(IDelegate *_delegate) const = 0;
};

#endif