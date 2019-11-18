#include <iostream>

template <typename T>
class Array {

public:

	Array(void):			_size(0), _arr(NULL){}
	Array(unsigned int n):	_size(n), _arr(new T[n]){}
	~Array(void)	{ delete[] _arr; }

	Array& operator=(const Array &rhs)
	{
		this->_size = rhs.size();
		this->_arr = new T[rhs.size()];
		for (int i = 0; i < this->_size; ++i)
			this->_arr[i] = rhs[i];
		return (*this);
	}
	Array(const Array &ref)	{ *this = ref; }

	T& operator[](int index)
	{
		if (!(index < this->_size))
			throw std::exception();
		return (this->_arr[index]);
	}

	unsigned int	size(void) const	{ return (this->_size); }

private:
	int	_size;
	T	*_arr;

};