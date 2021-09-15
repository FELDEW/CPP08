#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class OutOfLimitsException: public std::exception 
{
	virtual const char* what() const throw()
	{
		return ("Out of limits!");
	}
};

template<typename T>
typename T::iterator easyfind(T &map, int n)
{
	typename T::iterator it;
	it = find(map.begin(), map.end(), n);
	if (it == map.end())
		throw OutOfLimitsException();
	return (it);
}

#endif