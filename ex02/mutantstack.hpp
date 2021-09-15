#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>(){}
		~MutantStack(){}
		MutantStack(MutantStack<T> const & origin): std::stack<T>(origin){}
		MutantStack &operator=(MutantStack<T> const & origin) 
		{	
			if (this == &origin)
				return (*this);
			this->c = origin.c;
			return (*this);
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typename MutantStack<T>::iterator begin() { return (this->c.begin()); }
		typename MutantStack<T>::iterator end()	{ return (this->c.end()); }
		typename MutantStack<T>::const_iterator begin() const { return (this->c.begin()); }
		typename MutantStack<T>::const_iterator end() const { return (this->c.end()); }
};

#endif