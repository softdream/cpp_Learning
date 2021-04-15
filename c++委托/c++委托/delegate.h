#ifndef __DELEGATE_H_
#define __DELEGATE_H_

#include "delegate_base.h"
#include <typeinfo>
#include <list>

class CStaticDelegate : public IDelegate
{
public:
	typedef void(*Func)();

	CStaticDelegate(Func _func) : mFunc(_func) { }

	virtual bool isType(const std::type_info& _type) { return typeid(CStaticDelegate) == _type; }

	virtual void invoke() { mFunc(); }

	virtual bool compare(IDelegate *_delegate) const
	{
		if (0 == _delegate || !_delegate->isType(typeid(CStaticDelegate))) return false;
		CStaticDelegate * cast = static_cast<CStaticDelegate*>(_delegate);
		return cast->mFunc == mFunc;
	}

private:
	Func mFunc;
};

inline IDelegate* newDelegate(void(*_func)())
{
	return new CStaticDelegate(_func);
}

template<class T>
inline IDelegate* newDelegate(T * _object, void (T::*_method)())
{
	return new CMethodDelegate<T>(_object, _method);
}

class CMultiDelegate
{
public:
	typedef std::list<IDelegate*> ListDelegate;
	typedef ListDelegate::iterator ListDelegateIterator;
	typedef ListDelegate::const_iterator ConstListDelegateIterator;

	CMultiDelegate() { }
	~CMultiDelegate() { clear(); }

	bool empty() const
	{
		for (ConstListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
		{
			if (*iter) return false;
		}
		return true;
	}

	void clear()
	{
		for (ListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
		{
			if (*iter)
			{
				delete (*iter);
				(*iter) = 0;
			}
		}
	}

	CMultiDelegate& operator+=(IDelegate* _delegate)
	{
		for (ListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
		{
			if ((*iter) && (*iter)->compare(_delegate))
			{
				delete _delegate;
				return *this;
			}
		}
		mListDelegates.push_back(_delegate);
		return *this;
	}

	CMultiDelegate& operator-=(IDelegate* _delegate)
	{
		for (ListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
		{
			if ((*iter) && (*iter)->compare(_delegate))
			{
				if ((*iter) != _delegate) delete (*iter);
				(*iter) = 0;
				break;
			}
		}
		delete _delegate;
		return *this;
	}

	void operator()()
	{
		ListDelegateIterator iter = mListDelegates.begin();
		while (iter != mListDelegates.end())
		{
			if (0 == (*iter))
			{
				iter = mListDelegates.erase(iter);
			}
			else
			{
				(*iter)->invoke();
				++iter;
			}
		}
	}

private:
	CMultiDelegate(const CMultiDelegate& _event);
	CMultiDelegate& operator=(const CMultiDelegate& _event);

private:
	ListDelegate mListDelegates;
};

#endif
