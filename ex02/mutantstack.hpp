#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

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
		iterator begin() { return (this->c.begin()); }
		iterator end()	{ return (this->c.end()); }
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }
};

#endif