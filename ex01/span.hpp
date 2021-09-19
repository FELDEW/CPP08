#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <set>

class Span
{
	private:
		unsigned int _length;
		std::multiset<int> array;
	public:
		class SpanException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		Span();
		Span(unsigned int const N);
		virtual ~Span();
		Span(Span const & origin);
		Span &operator=(Span const & origin);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addNumber(int const newElement);
		unsigned int getSize();
		template<typename InputIterator>
		void addNumber(InputIterator _first, InputIterator _last)
		{
			if (this->array.size() + std::abs(std::distance(_first, _last)) > this->_length)
				throw Span::SpanException();
			this->array.insert(_first, _last);
		}
};

#endif