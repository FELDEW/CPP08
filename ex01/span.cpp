#include "span.hpp"

Span::Span(): _length(0)
{
}

Span::Span(unsigned int const N): _length(N)
{
}

Span::~Span()
{
}

Span::Span(Span const & origin)
{
	*this = origin;
}

const char* Span::SpanException::what() const throw()
{
	return ("Error in span!");
}

void Span::addNumber(int const newElement)
{
	if (this->array.size() >= this->_length)
		throw Span::SpanException();
	this->array.insert(newElement);
}

Span &Span::operator=(Span const & origin)
{
	if (this == &origin)
		return (*this);
	this->_length = origin._length;
	this->array.clear();
	this->array = origin.array;
	return (*this);
}

unsigned int Span::getSize()
{
	return (this->array.size());
}

unsigned int Span::shortestSpan()
{
	unsigned int diff;
	unsigned int shortestdiff;
	std::multiset<int>::iterator it;

	if (this->array.size() <= 1)
		throw Span::SpanException();
	it = this->array.begin();
	shortestdiff = std::abs(*it - *(++it));
	while (it != --this->array.end())
	{
		 diff = std::abs(*it - *(++it));
		 if (diff < shortestdiff)
		 	shortestdiff = diff;
	}
	return (shortestdiff);
}

unsigned int Span::longestSpan()
{
	unsigned int longestdiff;
	std::multiset<int>::iterator it;

	if (this->array.size() <= 1)
		throw Span::SpanException();
	longestdiff = std::abs(*this->array.begin() - *(--this->array.end()));
	return (longestdiff);
}
