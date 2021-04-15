#ifndef _ANY_H
#define _ANY_H
#include <string>
#include <algorithm>
class IAnyItem abstract
{
public:
	virtual ~IAnyItem() {}
	virtual const type_info& type() const = 0;
	virtual bool  empty() const = 0;
	virtual IAnyItem* clone() const = 0;
};

template<typename T>
class	AnyItem : public IAnyItem
{
public:
	AnyItem() :value(nullptr) {}
	explicit AnyItem(const T& val) :value(new T(val)) {}
	AnyItem(const AnyItem<T>& x) :value(new T(*x.value)) {

	}
	virtual ~AnyItem() {
		if (value) {
			delete value;
			value = nullptr;
		}
	}
	virtual const type_info& type() const {
		return value == nullptr ? typeid(void) : typeid(*value);
	}

	virtual bool	empty() const {
		return value == nullptr;
	}

	const T& get() {
		return *value;
	}

	AnyItem operator=(const T& val) {
		*value = val;
		return *this;
	}

	virtual IAnyItem* clone() const {
		IAnyItem* item = new AnyItem<T>(*this);
		return item;
	}
private:
	T*	value;
};

class	Any
{
public:
	Any() :item(nullptr) {}
	template<typename T>
	explicit Any(const T& val) :item(new AnyItem<T>(val)) {}
	template<typename T>
	explicit Any(const AnyItem<T>& x) :item(new AnyItem<T>(x)) {}
	Any(const Any& x) :item(nullptr) {
		if (x.getItem()) {
			auto p = x.getItem()->clone();
			item = p;
		}
	}
	~Any() {
		if (item) {
			delete item;
		}
	}
	Any operator=(const Any& x) {
		Any tmp(x);
		this->swap(tmp);
		return *this;
	}

	template<typename T>
	Any operator=(const AnyItem<T>& x) {
		Any tmp(x);
		this->swap(tmp);
		return *this;
	}

	template<typename T>
	Any operator=(const T& x) {
		Any tmp(x);
		this->swap(tmp);
		return *this;
	}

	bool empty() {
		return item == nullptr || item->empty();
	}

	const type_info& type() {
		return item->type();
	}

	template<typename T>
	const T& any_cast() {
		AnyItem<T>* anyitem = static_cast<AnyItem<T>*>(item);
		return anyitem->get();
	}

private:
	void swap(Any& x) {
		using std::swap;
		swap(this->item, x.item);
	}

	const IAnyItem* getItem() const {
		return item;
	}
private:
	IAnyItem* item;
};

#endif
